function findMaxLength(nums: number[]): number {
    let sum = 0
    let table = { 0: [-1, null] }
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === 0) {
            sum -= 1
        } else {
            sum += 1
        }
        if (table[sum]) {
            table[sum][1] = i
        } else {
            table[sum] = [i, null]
        }
    }

    let ans = 0

    Object.values(table).forEach(arr => {
        if (arr[1]) {
            const diff = arr[1] - arr[0]
            if (diff > ans) {
                ans = diff
            }
        }
    })

    return ans
};