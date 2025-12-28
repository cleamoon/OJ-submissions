const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

let ans = 0

for (let i = 0; i < lines.length; i++) {
  const line = lines[i]

  if (line.length === 0) break

  const strInBracket = line.match(/\[(.*?)\]/)?.[1]

  const strInParents = [...line.matchAll(/\((.*?)\)/g)].map(m => m[1])

  const strInRoundBracket = line.match(/\{(.*?)\}/)?.[1]

  console.log('bracket: ', strInBracket)
  console.log('parent: ', strInParents)
  console.log('round bracket: ', strInRoundBracket)

  const target = strInBracket.split('').map(e => e === '#' ? 1 : 0).join('')
  const switches = strInParents.map(str => str.split(',').map(Number))
  const junct = strInRoundBracket.split(',').map(Number)

  console.log('target: ', target)
  console.log('switches: ', switches)
  console.log('junct: ', junct)

  let min = 1000000

  const dp = (curr, rest, junc, res = 0) => {
  //  console.log('dp: ', curr, rest, target, junc, res)
    if (rest.length === 0) {
      if (curr.join('') === target && junc.every(j => j === 0)) {
        if (res < min) min = res
        return res
      }
      return
    }
    for (let t = 0; ; t++) {
      const s = rest[0]
      const currJunc = junc.map((e, i) => s.includes(i) ? e - t : e)
      if (currJunc.some(e => e < 0)) {
        return
      }
      dp(
        curr.map((e, i) => (s.includes(i) && t % 2 === 1) ? 1 - e : e), 
        rest.slice(1),
        [...currJunc],
        res + t,
      )
    }
  }

  dp(Array(target.length).fill(0), switches, [...junct])

  ans += min
}

console.log(ans)