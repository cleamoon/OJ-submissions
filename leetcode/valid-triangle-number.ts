function triangleNumber(nums: number[]): number {
  nums.sort((a, b) => {
      if (a > b) return 1
      else if (a < b) return -1
      else return 0
  })
  const length = nums.length
  let ans = 0
  for (let i = 0; i < length - 2; i++) {
      for (let j = i + 1; j < length - 1; j++) {
          for (let k = j + 1; k < length; k++) {
              if (nums[i] + nums[j] > nums[k]) ans += 1
          }
      }
  }
  return ans
};