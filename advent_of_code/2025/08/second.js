const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n').map(line => line.split(',').map(Number))

const distMatrix = new Array(lines.length).fill(0).map(() => new Array(lines.length).fill(Infinity))

distMatrix[0][0] = 0

for (let i = 0; i < lines.length - 1; i++) {
  for (let j = i + 1; j < lines.length; j++) {
    distMatrix[i][j] = (
      (lines[i][0] - lines[j][0]) * (lines[i][0] - lines[j][0]) +
      (lines[i][1] - lines[j][1]) * (lines[i][1] - lines[j][1]) +
      (lines[i][2] - lines[j][2]) * (lines[i][2] - lines[j][2])
    )
  }
}

const connectMatrix = [...new Array(lines.length)].map((_, i) => i)

const sortedDist = []

for (let i = 0; i < lines.length; i++) {
  for (let j = i + 1; j < lines.length; j++) {
    sortedDist.push({
      n1: i,
      n2: j,
      dist: distMatrix[i][j],
      n1p: lines[i],
      n2p: lines[j],
    })
  }
}

sortedDist.sort((a, b) => a.dist - b.dist)

for (let i = 0; i < sortedDist.length; i++) {
  const { n1, n2, n1p, n2p } = sortedDist[i]

  const val = connectMatrix[n2]

  for (let j = 0; j < connectMatrix.length; j++) {
    if (connectMatrix[j] === val) {
      connectMatrix[j] = connectMatrix[n1]
    }
  }

  if (connectMatrix.every(e => e === connectMatrix[0])) {
    console.log(n1p[0] * n2p[0])
    break
  }
}

