const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n').map(line => line.split(''))

let ans = 0

let pos = {
  [lines[0].indexOf('S')]: 1
}

for (let i = 1; i < lines.length; i++) {
  const new_pos = {}

  const keys = Object.keys(pos)
  for (let j = 0; j < keys.length; j++) {
    const x = keys[j]
    if (lines[i][x] === '^') {
      new_pos[Number(x) - 1] = (new_pos[Number(x) - 1] ?? 0) + pos[x]
      new_pos[Number(x) + 1] = (new_pos[Number(x) + 1] ?? 0) + pos[x]
    } else {
      new_pos[x] = (new_pos[x] ?? 0) + pos[x]
    }
  }

  pos = new_pos
}

const keys = Object.keys(pos)
for (let j = 0; j < keys.length; j++) {
  const x = keys[j]
  ans += pos[x]
}

console.log(ans)