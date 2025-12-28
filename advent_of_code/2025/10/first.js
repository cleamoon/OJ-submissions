const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

let ans = 0

for (let i = 0; i < lines.length; i++) {
  const line = lines[i]

  const strInBracket = line.match(/\[(.*?)\]/)?.[1]

  const strInParents = [...line.matchAll(/\((.*?)\)/g)].map(m => m[1])

  const target = strInBracket.split('').map(e => e === '#' ? 1 : 0)
  const switches = strInParents.map(str => str.split(',').map(Number))

  let min = Infinity

  const dp = (curr, rest, res = 0) => {
    if (rest.length === 0) {
      if (curr.join('') === target.join('')) {
        if (res < min) min = res
        return res
      }
      return Infinity
    }
    dp(curr.map((e, i) => rest[0].includes(i) ? 1 - e : e), rest.slice(1), res + 1)
    dp(curr, rest.slice(1), res)
  }

  dp(Array(target.length).fill(0), switches)

  ans += min
}

console.log(ans)