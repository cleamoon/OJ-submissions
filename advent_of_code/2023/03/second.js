const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

const listOfNumbers = []

const isDigit = (ch) => ch >= '0' && ch <= '9'

for (let l = 0; l < lines.length; l++) {
  const line = lines[l]
  let currentState = 'out'
  let currentNumber = ''
  for (let i = 0; i < line.length; i++) {
    const ch = line[i]
    if (isDigit(ch)) {
      if (currentState === 'out') {
        currentNumber = ch
        currentState = 'in'
      } else {
        currentNumber += ch
      }
    } else {
      if (currentState === 'in') {
        listOfNumbers.push({
          number: Number(currentNumber),
          line: l,
          index: i - currentNumber.length,
          length: currentNumber.length,
        })
        currentState = 'out'
      }
    }
  }
  if (currentState === 'in') {
    listOfNumbers.push({
      number: Number(currentNumber),
      line: l,
      index: line.length - currentNumber.length,
      length: currentNumber.length,
    })
  }
}

let sum = 0

const listOfGears = {}

for (let n = 0; n < listOfNumbers.length; n++) {
  const { number, line, index, length } = listOfNumbers[n]
  let found = false
  for (let l = Math.max(line - 1, 0); l <= Math.min(line + 1, lines.length - 1); l++) {
    if (found) break
    for (let i = Math.max(index - 1, 0); i <= Math.min(index + length, lines[l].length - 1); i++) {
      const ch = lines[l][i]
      if (ch === '*') {
        if (`${l}-${i}` in listOfGears) {
          listOfGears[`${l}-${i}`].push(number)
        } else {
          listOfGears[`${l}-${i}`] = [number]
        }
      }
    }
  }
}

for (const gear in listOfGears) {
  const numbers = listOfGears[gear]
  if (numbers.length === 2) {
    sum += numbers[0] * numbers[1]
  }
}

console.log(sum)