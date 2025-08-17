const fs = require('node:fs')

const input = fs.readFileSync('./input.txt', 'utf8')

const lines = input.split('\n')

let seeds_ranges = lines[0].split(' ').slice(1).map(Number)

let need_ranges = []

for (let i = 0; i < seeds_ranges.length - 1; i += 2) {
    const start = seeds_ranges[i]
    const range = seeds_ranges[i + 1]
    need_ranges.push({ start, range })
}

console.log('seeds:', need_ranges)

let ln = 1

const nodes = ["seed", "soil", "fertilizer", "water", "light", "temperature", "humidity", "location"]

for (let n = 0; n < nodes.length - 1; n++) {
    console.log(`${nodes[n]}-to-${nodes[n + 1]}`)

    do {
        ln += 1
    } while (!lines[ln].startsWith(`${nodes[n]}-to-${nodes[n + 1]} map`))
    ln += 1

    let supply_ranges = []

    while (true) {
        const line = lines[ln]
        if (!line) break
        const [need, supply, range] = line.split(' ').map(Number)

        supply_ranges.push({ supply, need, range })

        supply_ranges.sort((a, b) => a.supply - b.supply)

        ln += 1
    }

    console.log('supply ranges:', supply_ranges)

    let new_needs = []

    for (let i = 0; i < need_ranges.length; i++) {
        let { start: need_start, range: need_range } = need_ranges[i]
        let id = 0
        const need_end = need_start + need_range
        while (true) {
            if (id >= supply_ranges.length) {
                new_needs.push({ start: need_start, range: need_range })
                break
            }

            const { supply: supply_start, need: supply_need, range: supply_range } = supply_ranges[id]

            let supply_end = supply_start + supply_range

            if (supply_end <= need_start) {
                id += 1
                continue
            }

            if (supply_start > need_start) {
                if (need_end <= supply_start) {
                    new_needs.push({ start: need_start, range: need_range })
                    break
                }
                if (need_end > supply_end) {
                    new_needs.push({
                        start: need_start,
                        range: supply_start - need_start,
                    })
                    need_start = supply_start
                    need_range -= supply_start - need_start
                    continue
                } else {
                    new_needs.push({
                        start: need_start,
                        range: need_range,
                    })
                    break
                }
            }

            if (supply_end >= need_end) {
                new_needs.push({
                    start: supply_need + (need_start - supply_start),
                    range: need_range, // 22 - 15 = 7
                })
                break
            } else {
                const used_range = supply_end - need_start
                new_needs.push({
                    start: supply_need + (need_start - supply_start),
                    range: used_range,
                })
                need_start += used_range // 12 + 3 = 15
                need_range -= used_range // 10 - 3 = 7
                id += 1
            }

            console.log('new need:', new_needs[new_needs.length - 1])
        }

    }
    need_ranges = [...new_needs]
    new_needs = []
}

const ans = need_ranges.reduce((acc, { start }) => start < acc ? start : acc, Infinity)

console.log(ans)
