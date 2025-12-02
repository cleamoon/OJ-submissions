const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split(',')

let ans = 0

for (const line of lines) {
  const [a, b] = line.split('-').map(Number)

  for (let i = a; i <= b; i++) {
    const str = i.toString()
    if (str.length % 2 !== 0) continue
    const mid = str.length / 2
    const left = str.slice(0, mid)
    const right = str.slice(mid)
    if (left === right) {
      ans += Number(str)
    }
  }
}

console.log(ans)