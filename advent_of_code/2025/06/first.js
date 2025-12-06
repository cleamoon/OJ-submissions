const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

const nums = lines.map(line => line.split(/(\s+)/g)).slice(0, -1).map(line => line.filter(e => e > 0).map(Number))

const ops = lines.slice(-1)[0].split(/(\s+)/g).filter(e => e.startsWith('+') || e.startsWith('*'))

let ans = 0

for (let i = 0; i < nums[0].length; i++) {
  let curr = 0
  if (ops[i] === '+') {
    curr = 0
  } else {
    curr = 1
  }
  for (let j = 0; j < nums.length; j++) {
    if (ops[i] === '+') {
      curr += nums[j][i]
    } else {
      curr *= nums[j][i]
    }
  }
  ans += curr
}

console.log(ans)