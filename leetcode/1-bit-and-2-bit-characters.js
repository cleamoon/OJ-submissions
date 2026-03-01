/**
 * @param {number[]} bits
 * @return {boolean}
 */
var isOneBitCharacter = function(bits) {
    let last = 0
    for(let i = 0; i < bits.length; i++) {
        if (bits[i] == '0') {
            last = 0
        }
        else {
            last = 1
            i++
        }
    }
    return last == 0
};