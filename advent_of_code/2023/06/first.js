const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

const times = lines[0].split(' ').filter(Boolean).slice(1).map(Number)
const distances = lines[1].split(' ').filter(Boolean).slice(1).map(Number)

console.log(times)
console.log(distances)

const ways = []

for (let i = 0; i < times.length; i++) {
    let way = 0
    const time = times[i]
    for (let j = 1; j < time - 1; j++) {
        if (j * (time - j) > distances[i]) {
            way++
        }
    }
    ways.push(way)
}

console.log(ways)

const ans = ways.reduce((a, b) => a * b, 1)

console.log(ans)