const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

let seeds = lines[0].split(' ').slice(1).map(Number)

console.log(seeds)

let ln = 1

const nodes = ["seed", "soil", "fertilizer", "water", "light", "temperature", "humidity", "location"]

let needs = seeds

for (let n = 0; n < nodes.length - 1; n++) {
    console.log(`${nodes[n]}-to-${nodes[n + 1]}`)
    
    do {
        ln += 1
    } while (!lines[ln].startsWith(`${nodes[n]}-to-${nodes[n + 1]} map`))
    ln += 1

    let supplies = []

    while (true) {
        const line = lines[ln]
        if (!line) break
        const [supply, need, range] = line.split(' ').map(Number)
        for (let i = 0; i < needs.length; i++) {
            if (needs[i] >= need && needs[i] < need + range) {
                supplies.push(supply + needs[i] - need)
                needs[i] = -1
            }
        }
        if (supplies.length === needs.length) break
        ln += 1
    }

    for (let i = 0; i < needs.length; i++) {
        if (needs[i] !== -1) {
            supplies.push(needs[i])
        }
    }

    console.log(supplies)

    needs = supplies
}

const ans = Math.min(...needs)

console.log(ans)
