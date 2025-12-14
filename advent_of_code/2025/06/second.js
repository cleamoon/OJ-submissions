const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

const matrix = lines.map(line => line.split(''))

const transpose = new Array(matrix[0].length).fill(0).map(() => new Array(matrix.length).fill(0))

for (let i = 0; i < matrix[0].length; i++) {
  for (let j = 0; j < matrix.length; j++) {
    transpose[i][j] = matrix[j][i]
  }
}

let ans = 0

let numbers = []
let ops = null

for (let i = 0; i <= transpose.length; i++) {
  const line = transpose[i]
  if (i === transpose.length || line.every(e => e === line[0])) {
    const res = ops === '+'
      ? numbers.reduce((a, b) => a + b, 0)
      : numbers.reduce((a, b) => a * b, 1)
    ans += res

    numbers = []
    ops = null
    continue
  }
  const number = Number(line.slice(0, -1).join(''))
  if (number > 0) numbers.push(number)
  if (line[line.length - 1] === '+') {
    ops = '+'
  } else if (line[line.length - 1] === '*') {
    ops = '*'
  }
}

console.log(ans)