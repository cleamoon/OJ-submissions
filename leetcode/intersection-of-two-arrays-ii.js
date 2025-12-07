/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
  let s = [...nums1]
  const s2 = []
  for (let i = 0; i < nums2.length; i++) {
      for(let j = 0; j < s.length; j++) {
          if (nums2[i] === s[j]) {
              s2.push(nums2[i])
              s.splice(j, 1)
              break
          }
      }
  }
  return s2
};