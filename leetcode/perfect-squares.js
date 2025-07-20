/**
 * @param {number} n
 * @return {number}
 */
var numSquares = function(n) {
    let lst = Array.from({length: n + 1}, (_, i) => Infinity)
    for (let i = 1; i <= Math.sqrt(n); i++) {
        lst[i * i] = 1;
    }

    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= Math.sqrt(i); j++) {
            lst[i] = Math.min(lst[i], lst[i - j * j] + 1);
        }
    }
    return lst[n];
};