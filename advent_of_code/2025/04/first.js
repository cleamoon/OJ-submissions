const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

const map = lines.map(line => line.split(''))

let ans = 0

for (let i = 0; i < map.length; i++) {
  for (let j = 0; j < map[i].length; j++) {
    if (map[i][j] === '@') {
      let count = 0
      for (let p = -1; p <= 1; p++) {
        for (let q = -1; q <= 1; q++) {
          if (
            (p === 0 && q === 0)
            || i + p < 0
            || i + p >= map.length
            || j + q < 0
            || j + q >= map[i].length
          ) {
            continue
          }
          if (map[i + p][j + q] === '@') {
            count += 1
          }
        }
      }
      if (count < 4) {
        ans += 1
      }
    }
  }
}

console.log(ans)