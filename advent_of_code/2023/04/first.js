const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

let ans = 0

const power2 = (n) => {
  if (n === 0) return 0

  let res = 1
  for (let i = 0; i < n - 1; i++) {
    res *= 2
  }

  return res
}

for (const line of lines) {
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

  ans += power2(win)
}

console.log(ans)
