const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n').map(line => line.split(''))

let ans = 0

let pos = [lines[0].indexOf('S')]

for (let i = 1; i < lines.length; i++) {
  const new_pos = new Set()

  for (let j = 0; j < pos.length; j++) {
    const x = pos[j]
    if (lines[i][x] === '^') {
      new_pos.add(x - 1)
      new_pos.add(x + 1)
      ans += 1
    } else {
      new_pos.add(x)
    }
  }

  pos = Array.from(new_pos)
}

console.log(ans)