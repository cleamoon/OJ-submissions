/**
 * @param {number[]} nums
 * @return {string[]}
 */
var summaryRanges = function(nums) {
  let res = []
  let i = 0
  while (i < nums.length) {
      let curr = nums[i]
      let begin = curr
      while (i < nums.length) {
          if (nums[i + 1] === curr + 1) {
              i += 1
              curr += 1
          } else {
              break
          }
      }
      if (curr === begin) {
          res.push(`${curr}`)
      } else {
          res.push(`${begin}->${curr}`)
      }
      i += 1
  }
  return res
};