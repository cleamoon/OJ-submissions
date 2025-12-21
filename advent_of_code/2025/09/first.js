const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n').map(line => line.split(',').map(Number))

let maxArea = -1

for (let i = 0; i < lines.length; i++) {
  for (let j = i + 1; j < lines.length; j++) {
    const p1 = lines[i]
    const p2 = lines[j]
    const area = ((Math.abs(p1[0] - p2[0]) + 1) * Math.abs((p1[1] - p2[1]) + 1))
    maxArea = area > maxArea ? area : maxArea
  }
}

console.log(maxArea)
