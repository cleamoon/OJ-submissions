/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    nums.sort((a, b) => {
        if (a < b) return -1
        if (a > b) return 1
        return 0
    })
    let ans = [[]]

    for(let i = 0; i < nums.length; i++) {
        for(let j = 0; j < ans.length; j++) {
            const elem = ans[j]
            const len = elem.length
            if (len > 0 && elem[len - 1] >= nums[i]) continue;
            ans.push([...elem, nums[i]])
        }
    }

    return ans
};