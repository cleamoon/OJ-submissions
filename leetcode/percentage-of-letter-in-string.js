/**
 * @param {string} s
 * @param {character} letter
 * @return {number}
 */
var percentageLetter = function(s, letter) {
    let c = 0
    s.split('').forEach(l => {
        if (letter === l) c += 1
    })
    return Math.floor(c / s.length * 100)
};