function getSneakyNumbers(nums: number[]): number[] {
    let li: boolean[] = []
    let ans: number[] = []
    for(let i = 0; i < nums.length - 2; i++) {
        li.push(false)
    }
    for(let i = 0; i < nums.length; i++) {
        if (!li[nums[i]]) {
            li[nums[i]] = true 
        } else {
            ans.push(nums[i])
        }
    }
    return ans
};