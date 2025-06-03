/**
 * @param {number[]} nums
 * @return {number}
 */
var specialArray = function(nums) {
    nums.sort((a, b) => {
        if (a > b) return -1
        if (a < b) return 1
        return 0
    })

    for (let i = 1; i <= nums.length; i += 1) {
        if (nums[i - 1] >= i && (i === nums.length || nums[i] < i)) {
            return i
        }
    }

    return -1
};