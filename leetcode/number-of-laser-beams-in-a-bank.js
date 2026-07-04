/**
 * @param {string[]} bank
 * @return {number}
 */
var numberOfBeams = function(bank) {
    const cnt = []
    const w = bank.length
    const l = bank[0].length
    for(let i = 0; i < w; i++) {
        let n = 0
        for (let j = 0; j < l; j++) {
            if (bank[i][j] == '1') {
                n += 1
            }
        }
        if (n > 0) {
            cnt.push(n)
        }
    }
    console.log(cnt)
    if (cnt.length <= 1) return 0
    let ans = 0
    for (let i = 0; i < cnt.length - 1; i++) {
        ans += cnt[i] * cnt[i + 1]
    }
    return ans
};
