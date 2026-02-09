/**
 * @param {string} paragraph
 * @param {string[]} banned
 * @return {string}
 */
var mostCommonWord = function (paragraph, banned) {
    const words = paragraph.split(/\W+/)
        .filter(w => w.length > 0)
        .map(w => w.toLowerCase())
    const m = new Map()
    words.forEach(w => {
        const i = m.get(w)
        if (banned.includes(w)) return
        if (!i) {
            m.set(w, 1)
        } else {
            m.set(w, i + 1)
        }
    })
    let mc = -1, mw = null
    m.forEach((v, k) => {
        if (v > mc) {
            mw = k
            mc = v
        }
    })

    return mw
};