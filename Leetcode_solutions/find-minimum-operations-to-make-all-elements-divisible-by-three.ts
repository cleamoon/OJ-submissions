function minimumOperations(nums: number[]): number {
    return nums.reduce((acc, e) => acc + Math.min(e % 3, 3 - e % 3), 0)
};