function calc(nums: number[], curr: number[] = [], idx: number = 0) {
    if (idx === nums.length) {
        if (curr.length === 0) return 0
        let xor = curr[0]
        for(let i = 1; i < curr.length; i++) {
            xor = xor ^ curr[i]
        }
        return xor
    }
    return calc(nums, [...curr, nums[idx]], idx + 1) + calc(nums, curr, idx + 1)
}

function subsetXORSum(nums: number[]): number {
    return calc(nums)
};