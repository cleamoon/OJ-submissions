function numIdenticalPairs(nums: number[]): number {
    let m = new Map<number, number>()
    for (let i = 0; i < nums.length; i++) {
        const exist = m.get(nums[i])
        if (exist) {
            m.set(nums[i], exist + 1)
        } else {
            m.set(nums[i], 1)
        }
    }
    let li = Array.from(m.values())
    let ans = 0
    for (let i = 0; i < li.length; i++) {
        if (li[i] > 1) {
            ans += li[i] * (li[i] - 1) / 2
        }
    }
    return ans
};