/**
 * @param {string} s
 * @param {character} c
 * @return {number[]}
 */
var shortestToChar = function(s, c) {
    const ans = [...new Array(s.length)].map(_ => s.length + 1)
    let l = -1
    for(let i = 0; i < s.length; i++) {
        if (s[i] === c) {
            l = i
            ans[i] = 0
        } else {
            if (l != -1) {
                ans[i] = Math.min(ans[i], i - l)
            }
        }
    }
    l = -1
    for(let i = s.length - 1; i >= 0; i--) {
        if (s[i] === c) {
            l = i
            ans[i] = 0
        } else {
            if (l != -1) {
                ans[i] = Math.min(ans[i], l - i)
            }
        }
    }
    return ans
};
