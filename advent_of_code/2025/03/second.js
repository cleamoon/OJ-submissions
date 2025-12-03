const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

let ans = 0

for (const line of lines) {
  let pMax = -1
  let curr = 0

  for (let n = 0; n < 12; n++) {
    curr *= 10

    let dMax = -1

    for (let i = pMax + 1; i < line.length - (11 - n); i++) {
      const d = Number(line[i])
      if (d > dMax) {
        dMax = d
        pMax = i
      }
    }

    curr += dMax
  }

  ans += curr
}


console.log(ans)