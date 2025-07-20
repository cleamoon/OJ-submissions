/**
 * @param {number[]} pref
 * @return {number[]}
 */
var findArray = function (pref) {
    let ans = [pref[0]]
    let xorred = pref[0]

    for (let i = 1; i < pref.length; i++) {
        let newxor = pref[i] ^ xorred
        ans.push(newxor)
        xorred = newxor ^ xorred
    }

    return ans
};