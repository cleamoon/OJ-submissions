const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

var sum = 0

const parseLine = (line) => {
  if (line === '') { return }
  const [_, gamesStr] = line.split(': ')

  const games = gamesStr.split('; ')

  const minimumAmount = {}

  for (const game of games) {
    const colors = game.split(', ')
    const colorAmount = {}
    for (const color of colors) {
      const [amount, colorName] = color.split(' ')
      colorAmount[colorName] = parseInt(amount)
    }
    for (const color in colorAmount) {
      if (!minimumAmount[color] || colorAmount[color] > minimumAmount[color]) {
        minimumAmount[color] = colorAmount[color]
      }
    }
  }
  let product = 1
  for (const color in minimumAmount) {
    product *= minimumAmount[color]
  }
  sum += product
  return sum
}

lines.map(parseLine)

console.log(sum)
