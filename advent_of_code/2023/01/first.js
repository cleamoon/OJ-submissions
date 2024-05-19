const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

var sum = 0

for (const line of lines) {
  const numbers = line.split('').filter(Number).map((n) => parseInt(n, 10))
  if (numbers.length === 0) continue
  sum += numbers[0] * 10 + numbers[numbers.length - 1]
}

console.log(sum)