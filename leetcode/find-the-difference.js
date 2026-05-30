/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    const m1 = new Map()
    const m2 = new Map()
    s.split('').forEach(c => {
        const e = m1.get(c)
        if (e) m1.set(c, e + 1)
        else m1.set(c, 1)
    })
    t.split('').forEach(c => {
        const e = m2.get(c)
        if (e) m2.set(c, e + 1)
        else m2.set(c, 1)
    })
    let ans
    m2.forEach((v, k) => {
        const ov = m1.get(k)
        if (ov !== v) ans = k
    })
    return ans
};