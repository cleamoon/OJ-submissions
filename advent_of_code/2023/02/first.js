const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

var sum = 0

const maximumColors = {
  'red': 12,
  'green': 13,
  'blue': 14,
}

const parseLine = (line) => {
  if (line === '') { return }
  const [gameTitle, gamesStr] = line.split(': ')
  const [_, numberStr] = gameTitle.split(' ')
  const number = parseInt(numberStr)

  const games = gamesStr.split('; ')

  let isPossible = true
  for (const game of games) {
    if (!isPossible) { break }
    const colors = game.split(', ')
    const colorAmount = {}
    for (const color of colors) {
      const [amount, colorName] = color.split(' ')
      colorAmount[colorName] = parseInt(amount)
    }
    for (const color in colorAmount) {
      if (!maximumColors[color] || colorAmount[color] > maximumColors[color]) {
        isPossible = false
        break
      }
    }
  }
  if (isPossible) {
    sum += number
  }
  return sum
}

lines.map(parseLine)

console.log(sum)
