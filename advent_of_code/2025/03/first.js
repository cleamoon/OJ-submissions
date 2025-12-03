const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

let ans = 0

let curr = 50

for (const line of lines) {
  let d1 = -1
  let d2 = -1
  let p1 = -1
  for (let i = 0; i < line.length - 1; i++) {
    const d = Number(line[i])
    if (d > d1) {
      d1 = d
      p1 = i
    }
  }
  for (let i = p1 + 1; i < line.length; i++) {
    const d = Number(line[i])
    if (d > d2) {
      d2 = d
      p2 = i
    }
  }

  ans += d1 * 10 + d2
}


console.log(ans)