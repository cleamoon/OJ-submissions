/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = function(nums) {
    const l = nums.length
    let arr = new Array(l).fill(Infinity)
    arr[0] = 0
    for (let i = 0; i < l; i++) {
        const s = nums[i]
        for (let j = 1; j <= s; j++) {
            if (i + j >= l) break
            arr[i + j] = Math.min(arr[i] + 1, arr[i + j])
        }
    }
    return arr[l - 1]
};