
// Inserting the Images
function insertImage() {

    document.querySelectorAll('.box').forEach(image => {
        if (image.innerText !== "0") {
            if (image.innerText == 'Wpawn' || image.innerText == 'Bpawn') {
                image.innerHTML = `${image.innerText} <img class='allimg allpawn' src="pieces/${image.innerText}.png" alt="">`
                image.style.cursor = 'pointer'

            }

            else {

                image.innerHTML = `${image.innerText} <img class='allimg' src="pieces/${image.innerText}.png" alt="">`
                image.style.cursor = 'pointer'
            }
        }
    })
}
insertImage()

async function sendState() {
    pgn = board_image_to_pgn()
    json_data = {pgn}
    const options = {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(json_data)
    };
    const rawResponse = await fetch('/pl', options); // add .then() to catch promise
}
//sendState() 

// convert html board input into a pgn/fen use C logic to convert innertext to chars
function board_image_to_pgn() {
    pgn = ""
    rawText = []
    i=0
    document.querySelectorAll('.box').forEach(image => {
        rawText[i++] = image.innerText
    })
    i=0
    pgn_i=0
    while (i < 64) {
        if (pgn_i != 0 && (pgn_i) % 8 == 0) {
            pgn += '/'
        }
        curr_square = rawText[64-i]
        if (curr_square == '0') {
            empty_count = 0
            while (rawText[i] == '0' && empty_count < 8){
                empty_count++
                i++
            }
            pgn+=empty_count
            pgn_i+=empty_count
        }
        else {
            if (curr_square == "Wpawn") {
                pgn += "p"
            }
            else if (curr_square == "Bpawn") {
                pgn += "P"
            }
            else if (curr_square == "Wknight") {
                pgn += "n"
            }
            else if (curr_square == "Bknight") {
                pgn += "N"
            }
            else if (curr_square == "Wbishop") {
                pgn += "b"
            }
            else if (curr_square == "Bbishop") {
                pgn += "B"
            }
            else if (curr_square == "Wrook") {
                pgn += "r"
            }
            else if (curr_square == "Brook") {
                pgn += "R"
            }
            else if (curr_square == "Wqueen") {
                pgn += "q"
            }
            else if (curr_square == "Bqueen") {
                pgn += "Q"
            }
            else if (curr_square == "Wking") {
                pgn += "k"
            }
            else if (curr_square == "Bking") {
                pgn += "K"
            }
            i++
            pgn_i++
        }
    }
    return pgn
}

//Coloring
function coloring() {
    const color = document.querySelectorAll('.box')

    color.forEach(color => {

        square = color.id
        file = square % 8   
        rank = Math.floor((square-1) / 8)
        if ((rank+file) % 2 == 0) {
            color.style.backgroundColor = 'rgb(100, 75, 43)'
        }
        if ((rank+file) % 2 !== 0) {
            color.style.backgroundColor = 'rgb(240, 201, 150)'
        }

    })
}
coloring()


const imgs = document.querySelectorAll('img');

imgs.forEach(img => {
  console.log(img.innerText)
  img.addEventListener('click', squareClicked(img.textContent));
});

function squareClicked(piece) {
    //console.log(piece)
}