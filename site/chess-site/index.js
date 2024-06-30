const cool = require('cool-ascii-faces')
const express = require('express')
const path = require('path')
var cors = require('cors')
const { exec } = require('child_process');
var XMLHttpRequest = require('xhr2');

const { Pool } = require('pg')

const pool = new Pool({
  connectionString: process.env.DATABASE_URL,
  ssl: {
    rejectUnauthorized: false
  }
})

const PORT = process.env.PORT || 5001
express()
  .use(express.static(path.join(__dirname, 'public')))
  .use(cors())
  .use(express.json())
  .set('views', path.join(__dirname, 'views'))
  .set('view engine', 'ejs')
  .get('/', (req, res) => {
    var fs = require('fs');
    res.render('pages/chess.ejs');
    if (req.query.fen != undefined){
      console.log(req.query)
      writer = fs.createWriteStream('public/chess/output.txt');
      writer.write(req.query.fen);
    }
    // const Http = new XMLHttpRequest();
    // const url='http://localhost:5001/pl';
    // Http.open("GET", url);
    // Http.send();
    // Http.onreadystatechange = function(){
    //   console.log(this.readyState);
    //   if (this.readyState == 4) {
    //     console.log(Http.responseText)
    //     writer = fs.createWriteStream('public/chess/output.txt');
    //     writer.write(req.query.fen);
    //   }
    // }
  })
  .post('/pl', (req, res) => {
    var fs = require('fs');
    console.log(req.body);
    writer = fs.createWriteStream('public/chess/output.txt');
    writer.write(JSON.stringify(req.body));
  })

  .get('/bs/get', async (req, res) => {
    try {
      const client = await pool.connect();
      const result = await client.query('select * from board_state');
      results = { 'results': (result) ? result.rows : null };

      res.send(results);
      client.release();
    } catch (err) {
      console.error(err);
      res.send("Error " + err);
    }
  })
  .get('/bs/set', async (req, res) => {
    const client = await pool.connect();
    queries = setFEN(req.query.bs);
    old_bb = client.query(queries[a]);
    result = client.query(queries[b]);
    // do bitwise or
    res.send(queries);
  })
  .get('/cool', (req, res) => res.send(cool()))
  .get('/times', (req, res) => res.send(showTimes()))
  .post('/', (req, res) => {
    res.send(req.get())
    res.render('pages/chess')
  })

  .listen(PORT, () => console.log(`Listening on ${PORT}`))

function showTimes() {
  const times = process.env.TIMES || 5
  let result = ''
  for (i = 0; i < times; i++) {
    result += i + ' '
  }
  return result
}

function readTextFile(file) {
  var rawFile = new XMLHttpRequest();
  rawFile.open("GET", file, false);
  rawFile.onreadystatechange = function () {
    if(rawFile.readyState === 4)  {
      if(rawFile.status === 200 || rawFile.status == 0) {
        var allText = rawFile.responseText;
        console.log(allText);
       }
    }
  }
  rawFile.send(null);
}

async function setFEN(fen) {
  const client = await pool.connect();
  rows = fen.split('/')
  const queries = []
  for (let row in rows) {
    for (let col in rows[row]) {
      square = row * 8 + col
      //queries.push(rows[row][col].charCodeAt(0))
      ascii_code = rows[row][col].charCodeAt(0)
      if (ascii_code <= 57 && ascii_code >= 49) {
        //set in innerhtml or database?
        // lets try database

      }
      else {
        bb_square = 1 << square
        // 112 -> 'p'
        if (ascii_code == 112) {
          sql_get = "select bb_wpawn from board_state"
          result = await client.query(sql_get);
          sql_update = "update board_state set bb_wpawn=".concat(result | bb_square)
          result = await client.query(sql_update);
          var dict = new Object();
          dict = { a: sql_get, b: sql_update }
          queries.push(dict);
        }
        // 80 -> 'P'
        else if (ascii_code == 80) {
          sql_get = "select bb_bpawn from board_state"
          result = await client.query(sql_get);
          sql_update = "update board_state set bb_bpawn=".concat(result | bb_square)
          result = await client.query(sql_update);
          var dict = new Object();
          dict = { a: sql_get, b: sql_update }
          queries.push(dict);
        }
        // 110 -> 'n'
        else if (ascii_code == 110) {
          sql_get = "select bb_wknight from board_state"
          result = await client.query(sql_get);
          sql_update = "update board_state set bb_wknight=".concat(result | bb_square)
          result = await client.query(sql_update);
          var dict = new Object();
          dict = { a: sql_get, b: sql_update }
          queries.push(dict);
        }
        // 78 -> 'N'
        else if (ascii_code == 78) {
          sql_get = "select bb_bknight from board_state"
          result = await client.query(sql_get);
          sql_update = "update board_state set bb_bknight=".concat(result | bb_square)
          result = await client.query(sql_update);
          var dict = new Object();
          dict = { a: sql_get, b: sql_update }
          queries.push(dict);
        }
        // 98 -> 'b'
        else if (ascii_code == 98) {
          sql_get = "select bb_wbishop from board_state"
          result = await client.query(sql_get);
          sql_update = "update board_state set bb_wbishop=".concat(result | bb_square)
          result = await client.query(sql_update);
          var dict = new Object();
          dict = { a: sql_get, b: sql_update}
          queries.push(dict);
        }
        // 66 -> 'B'
        else if (ascii_code == 66) {
          sql_get = "select bb_bbishop from board_state"
          result = await client.query(sql_get);
          sql_update = "update board_state set bb_bbishop=".concat(result | bb_square)
          result = await client.query(sql_update);
          var dict = new Object();
          dict = { a: sql_get, b: sql_update}
          queries.push(dict);
        }
        // 114 -> 'r'
        else if (ascii_code == 114) {
          sql_get = "select bb_wrook from board_state"
          result = await client.query(sql_get);
          sql_update = "update board_state set bb_wrook=".concat(result | bb_square)
          result = await client.query(sql_update);
          var dict = new Object();
          dict = { a: sql_get, b: sql_update}
          queries.push(dict);
        }
         // 82 -> 'R'
         else if (ascii_code == 82) {
          sql_get = "select bb_brook from board_state"
          result = await client.query(sql_get);
          sql_update = "update board_state set bb_brook=".concat(result | bb_square)
          result = await client.query(sql_update);
          var dict = new Object();
          dict = { a: sql_get, b: sql_update}
          queries.push(dict);
         }
        // 113 -> 'q'
        else if (ascii_code == 113) {
          sql_get = "select bb_wqueen from board_state"
          result = await client.query(sql_get);
          sql_update = "update board_state set bb_wqueen=".concat(result | bb_square)
          result = await client.query(sql_update);
          var dict = new Object();
          dict = { a: sql_get, b: sql_update}
          queries.push(dict);
        }
        // 81 -> 'Q'
        else if (ascii_code == 81) {
          sql_get = "select bb_bqueen from board_state"
          result = await client.query(sql_get);
          sql_update = "update board_state set bb_bqueen=".concat(result | bb_square)
          result = await client.query(sql_update);
          var dict = new Object();
          dict = { a: sql_get, b: sql_update}
          queries.push(dict);
        }
        // 107 -> 'k'
        else if (ascii_code == 107) {
          sql_get = "select bb_wking from board_state"
          result = await client.query(sql_get);
          sql_update = "update board_state set bb_wking=".concat(result | bb_square)
          result = await client.query(sql_update);
          var dict = new Object();
          dict = { a: sql_get, b: sql_update}
          queries.push(dict);
        }
        // 75 -> 'K'
        else if (ascii_code == 75) {
          sql_get = "select bb_bking from board_state"
          result = await client.query(sql_get);
          sql_update = "update board_state set bb_bking=".concat(result | bb_square)
          result = await client.query(sql_update);
          var dict = new Object();
          dict = { a: sql_get, b: sql_update}
          queries.push(dict);
        }
      }
    }
  }
  return queries
}

