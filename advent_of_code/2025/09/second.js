const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n').map(line => line.split(',').map(Number))

let areas = []

for (let i = 0; i < lines.length; i++) {
  for (let j = i + 1; j < lines.length; j++) {
    const p1 = lines[i]
    const p2 = lines[j]
    const area = ((Math.abs(p1[0] - p2[0]) + 1) * Math.abs((p1[1] - p2[1]) + 1))
    areas.push({ p1, p2, area })
  }
}

areas.sort((a, b) => b.area - a.area)

let matrix = Array.from({ length: Math.max(...lines.map(line => line[0])) + 2 }, () => Array(Math.max(...lines.map(line => line[1])) + 2).fill('.'))

console.log(matrix.length, matrix[0].length)

console.log('lines', lines)

let curr = [...lines[lines.length - 1]]
for (let i = 0; i < lines.length; i++) {
  const next = lines[i]
  console.log(i)
  console.log('from', curr)
  console.log('to', next)
  if (next[0] === curr[0]) {
    while (curr[1] !== next[1]) {
      curr[1] += next[1] > curr[1] ? 1 : -1
      matrix[curr[0]][curr[1]] = '#'
    }
  } else if (next[1] === curr[1]) {
    while (curr[0] !== next[0]) {
      curr[0] += next[0] > curr[0] ? 1 : -1
      matrix[curr[0]][curr[1]] = '#'
    }
  }
}

console.log(matrix.map(row => row.join('')).join('\n'))

let visited = new Set([`${curr[0]},${curr[1]}`])

curr = [0, 0]
queue = [curr]
while (queue.length > 0) {
  const curr = queue.shift()
  if (visited.has(`${curr[0]},${curr[1]}`)) {
    continue
  }
  visited.add(`${curr[0]},${curr[1]}`)
  if (curr[0] < 0 || curr[0] >= matrix.length || curr[1] < 0 || curr[1] >= matrix[0].length || matrix[curr[0]][curr[1]] === '#') {
    continue
  }
  matrix[curr[0]][curr[1]] = 'x'
  queue.push([curr[0] + 1, curr[1]])
  queue.push([curr[0] - 1, curr[1]])
  queue.push([curr[0], curr[1] + 1])
  queue.push([curr[0], curr[1] - 1])
}

console.log(matrix.map(row => row.join('')).join('\n'))

let maxArea = 0

for (const area of areas) {
  maxArea = area.area
  //  console.log('maxArea', maxArea, area)
  let found = false
  const minX = Math.min(area.p1[0], area.p2[0])
  const maxX = Math.max(area.p1[0], area.p2[0])
  const minY = Math.min(area.p1[1], area.p2[1])
  const maxY = Math.max(area.p1[1], area.p2[1])
  corners = [[minX, minY], [maxX, minY], [maxX, maxY], [minX, maxY]]
  curr = corners[3]
  for (let i = 0; i < 4; i++) {
    const next = corners[i]
    console.log(i)
    console.log('from', curr)
    console.log('to', next)
    if (next[0] === curr[0]) {
      while (curr[1] !== next[1]) {
        curr[1] += next[1] > curr[1] ? 1 : -1
        if (matrix[curr[0]][curr[1]] === 'x') {
          found = true
          break
        }
      }
    } else if (next[1] === curr[1]) {
      while (curr[0] !== next[0]) {
        curr[0] += next[0] > curr[0] ? 1 : -1
        if (matrix[curr[0]][curr[1]] === 'x') {
          found = true
          break
        }
      }
    }
    if (found) break
  }
  if (!found) {
    break
  }
}

console.log(maxArea)