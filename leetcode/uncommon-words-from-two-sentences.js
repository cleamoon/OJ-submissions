/**
 * @param {string} s1
 * @param {string} s2
 * @return {string[]}
 */
var uncommonFromSentences = function(s1, s2) {
    const a1 = s1.split(' ')
    const wc1 = a1.reduce((acc, e) => {
        if (acc.has(e)) {
            acc.set(e, acc.get(e) + 1)
        } else {
            acc.set(e, 1)
        }
        return acc
    }, new Map())
    const a2 = s2.split(' ')
    const wc2 = a2.reduce((acc, e) => {
        if (acc.has(e)) {
            acc.set(e, acc.get(e) + 1)
        } else {
            acc.set(e, 1)
        }
        return acc
    }, new Map())
    const ans = []
    a1.forEach(e => {
        if (!a2.includes(e)) {
            if (wc1.get(e) === 1) {
                ans.push(e)
            }
        }
    })
    a2.forEach(e => {
        if (!a1.includes(e)) {
            if (wc2.get(e) === 1) {
                ans.push(e)
            }
        }
    })
    return ans
};