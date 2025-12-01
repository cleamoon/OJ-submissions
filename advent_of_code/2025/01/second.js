const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

let ans = 0

let curr = 50

for (const line of lines) {
  const fst = line[0]
  const num = Number(line.slice(1))

  if (fst === 'L') {
    for (let i = 0; i < num; i++) {
      curr -= 1
      if (curr === 0) {
        ans += 1
      }
      if (curr < 0) {
        curr += 100
      }
    }
  } else {
    for (let i = 0; i < num; i++) {
      curr += 1
      if (curr >= 100) {
        curr -= 100
      }
      if (curr === 0) {
        ans += 1
      }
    }
  }
}

console.log(ans)