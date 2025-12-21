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

let curr = lines[lines.length - 1]
for (let i = 0; i < lines.length; i++) {
  const next = lines[i]
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
  if (curr[0] < 0 || curr[0] >= matrix.length || curr[1] < 0 || curr[1] >= matrix[0].length || matrix[curr[0]][curr[1]] > 0) {
    continue
  }
  matrix[curr[0]][curr[1]] = -1
  queue.push([curr[0] + 1, curr[1]])
  queue.push([curr[0] - 1, curr[1]])
  queue.push([curr[0], curr[1] + 1])
  queue.push([curr[0], curr[1] - 1])
}

// console.log(matrix)

let maxArea = 0

const pointInArea = (point, area) => {
  const { p1, p2 } = area
  return point[0] >= p1[0] && point[0] <= p2[0] && point[1] >= p1[1] && point[1] <= p2[1]
}

for (const area of areas) {
  let curr = lines[lines.length - 1]
  maxArea = area.area
  //  console.log('maxArea', maxArea, area)
  let found = false
  for (let i = 0; i < lines.length; i++) {
    const next = lines[i]
    if (next[0] === curr[0]) {
      while (curr[1] !== next[1]) {
        curr[1] += next[1] > curr[1] ? 1 : -1
        if (pointInArea(curr, area)) {
          found = true
          break
        }
      }
    } else if (next[1] === curr[1]) {
      while (curr[0] !== next[0]) {
        curr[0] += next[0] > curr[0] ? 1 : -1
        if (pointInArea(curr, area)) {
          found = true
          break
        }
      }
    }
    if (found) {
      break
    }
  }
  if (!found) {
    break
  }
}

console.log(maxArea)