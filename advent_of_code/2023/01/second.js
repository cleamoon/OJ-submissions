const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

var sum = 0

const WORDS = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
const DIGITS = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

for (const line of lines) {
  let found_first = false;
  let found_last = false;

  for(let begin = 0; begin < line.length; begin++) {
    if (found_first) break
    for (let i = 0; i < 10; i++) {
      const word = WORDS[i]
      if (line.substring(begin, begin + word.length) === word) {
        sum += i * 10
        found_first = true
        break
      }
    }
    for (let i = 0; i < 10; i++) {
      const word = DIGITS[i]
      if (line.substring(begin, begin + word.length) === word) {
        sum += i * 10
        found_first = true
        break
      }
    }
  }

  for(let end = line.length; end > 0; end--) {
    if (found_last) break
    for (let i = 0; i < 10; i++) {
      const word = WORDS[i]
      if (line.substring(end - word.length, end) === word) {
        sum += i
        found_last = true
        break
      }
    }
    for (let i = 0; i < 10; i++) {
      const word = DIGITS[i]
      if (line.substring(end - word.length, end) === word) {
        sum += i
        found_last = true
        break
      }
    }
  }
}

console.log(sum)