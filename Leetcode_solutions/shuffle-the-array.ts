function shuffle(nums: number[], n: number): number[] {
    let res: number[] = []
    const half = nums.length / 2
    for (let i = 0; i < half; i++) {
        res.push(nums[i])
        res.push(nums[i + half])
    }
    return res
};