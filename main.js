const { exec } = require('child_process');

const argValue = 'hello!';  // Sample arguments
const command = `./public/chess/testBitboardStr.x ${argValue}`;

exec(command, (error, stdout) => {
    if (error) {
        console.error(`Error: ${error.message}`);
        return;
    }
    console.log(`${stdout}`);
});