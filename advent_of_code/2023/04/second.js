const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

const numberOfCopies = Array(lines.length).fill(1)

for (let l = 0; l < lines.length; l++) {
  const line = lines[l]
  const [_, games] = line.split(': ')

  if (!games) continue

  const [winStr, ownStr] = games.split(' | ')

  const winNums = winStr.split(' ').filter(s => s !== '').map(Number)
  const ownNums = ownStr.split(' ').filter(s => s !== '').map(Number)

  let win = 0

  for (const winNum of winNums) {
    if (ownNums.includes(winNum)) {
      win++
    }
  }

  for (let i = 0; i < win; i++) {
    numberOfCopies[i + l + 1] += numberOfCopies[l]
  }
}

let ans = 0

for (let i = 0; i < lines.length; i++) {
  ans += numberOfCopies[i]
}

console.log(ans)
