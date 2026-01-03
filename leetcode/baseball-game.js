/**
 * @param {string[]} operations
 * @return {number}
 */
var calPoints = function (operations) {
    let arr = []
    for (let i = 0; i < operations.length; i++) {
        const op = operations[i]
        if (op === "C") {
            arr = arr.slice(0, -1)
        } else if (op === "D") {
            arr.push(arr[arr.length - 1] * 2)
        } else if (op === '+') {
            arr.push(arr[arr.length - 1] + arr[arr.length - 2])
        } else {
            arr.push(Number(op))
        }
    }
    return arr.reduce((acc, e) => {
        return acc + e
    }, 0)
};