/**
 * @param {string[]} logs
 * @return {number}
 */
var minOperations = function(logs) {
    let cur = 0
    logs.forEach(s => {
        if (s === './') return
        else if (s === '../') cur = Math.max(0, cur - 1)
        else cur += 1
    })
    return cur
};