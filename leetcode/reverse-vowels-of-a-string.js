/**
 * @param {string} s
 * @return {string}
 */
function isVwl(ch) {
    return ['a', 'e', 'i', 'o', 'u'].includes(ch.toLowerCase())
}

var reverseVowels = function(s) {
    let vl = []
    s.split('').forEach(ch => {
        if(isVwl(ch)) {
            vl.push(ch)
        }
    })

    let i = 0

    let res = []

    s.split('').forEach(ch => {
        if (isVwl(ch)) {
            res.push(vl[vl.length - 1 - i])
            i += 1
        } else {
            res.push(ch)
        }
    })

    return res.join('')
};
