const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

const time = Number(lines[0].split(' ').filter(Boolean).slice(1).join(''))
const distance = Number(lines[1].split(' ').filter(Boolean).slice(1).join(''))

console.log(time)
console.log(distance)

let way = 0
for (let j = 1; j < time - 1; j++) {
    if (j * (time - j) > distance) {
        way++
    }
}

console.log(way)
