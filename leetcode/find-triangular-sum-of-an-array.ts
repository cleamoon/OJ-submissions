/**
 * @param {number[]} nums
 * @return {number}
 */
var triangularSum = function(nums) {
  let res = nums
  while (res.length > 1) {
      let new_arr = []
      for(let i = 0; i < res.length - 1; i++) {
          new_arr.push((res[i] + res[i + 1]) % 10)
      }
      res = new_arr
  }
  return res[0]
};