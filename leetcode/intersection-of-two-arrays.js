/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
  const s = new Set()
  for (const n of nums1) {
      s.add(n)
  }
  const s2 = new Set()
  for (const n of nums2) {
      if(s.has(n)) {
          s2.add(n)
      }
  }
  return [...s2]
};