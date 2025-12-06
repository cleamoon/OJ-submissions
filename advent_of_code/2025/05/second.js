const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

let ranges = []

let ans = 0

for (curr = 0; curr < lines.length; curr++) {
  const line = lines[curr]
  if (line === '') {
    break
  }
  const [start, end] = line.split('-').map(Number)
  ranges.push([start, end])
}

ranges.sort((a, b) => a[0] - b[0])

for (let i = 0; i < ranges.length; i++) {
  let [start1, end1] = ranges[i]
  for (let j = i + 1; j < ranges.length; j++) {
    const [start2, end2] = ranges[j]
    if (end1 < start2) {
      break
    }
    if (end1 <= end2) {
      ranges[i] = [start1, end2]
      end1 = end2
    }
    ranges = ranges.filter((_, index) => index !== j)
    j--
  }
}

for (const range of ranges) {
  ans += range[1] - range[0] + 1
}

console.log(ans)