function minimumTotal(triangle: number[][]): number {
  let res = []
  for(let i = 0; i < triangle.length; i++) {
      const nums = triangle[i]
      if (res.length === 0) {
          res = [...nums]
      } else {
          let new_res = []
          for(let j = 0; j < nums.length; j++) {
              if (j === 0) {
                  new_res.push(nums[0] + res[0])
              } else {
                  const n1 = nums[j] + res[j - 1]
                  const n2 = nums[j] + res[j]
                  new_res.push(n1 > n2 ? n2 : n1)
              }
          }
          res = [...new_res]
      }
  }
  let ans = Infinity
  for(let i = 0; i < res.length; i++) {
      if (res[i] < ans) ans = res[i]
  }
  return ans
};