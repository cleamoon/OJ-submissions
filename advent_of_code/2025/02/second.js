const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split(',')

let ans = 0

for (const line of lines) {
  const [a, b] = line.split('-').map(Number)

  for (let i = a; i <= b; i++) {
    const str = i.toString()
    let found = false
    for (let j = 2; j <= str.length; j++) {
      if (str.length % j !== 0) continue
      const length = str.length / j
      const base = str.slice(0, length)
      for (let k = 1; k < j; k++) {
        const slice = str.slice(k * length, (k + 1) * length)
        if (slice !== base) {
          break
        }
        if (k === j - 1) {
          ans += Number(str)
          found = true
        }
      }
      if (found) break
    }
  }
}

console.log(ans)