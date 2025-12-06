const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

const ranges = []

let ans = 0

let curr = 0

for (curr = 0; curr < lines.length; curr++) {
  const line = lines[curr]
  if (line === '') {
    break
  }
  const [start, end] = line.split('-').map(Number)
  ranges.push([start, end])
}

ranges.sort((a, b) => a[0] - b[0])

for (; curr < lines.length; curr++) {
  const line = lines[curr]
  const val = Number(line)
  for (const range of ranges) {
    if (val >= range[0] && val <= range[1]) {
      ans += 1
      break
    }
  }
}


console.log(ans)