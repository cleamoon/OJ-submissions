/**
 * @param {number[]} arr
 * @return {number}
 */
var findLucky = function(arr) {
    const map = new Map()
    for(let i = 0; i < arr.length; i++) {
        const val = map.get(arr[i])
        if (val) {
            map.set(arr[i], val + 1)
        } else {
            map.set(arr[i], 1)
        }
    }
    let ans = -1
    map.forEach((v, k) => {
        if (Number(k) == v && v > ans) {
            ans = v
        }
    })
    return ans
};