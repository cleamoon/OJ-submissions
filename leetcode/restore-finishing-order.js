/**
 * @param {number[]} order
 * @param {number[]} friends
 * @return {number[]}
 */
var recoverOrder = function(order, friends) {
  let res = []
  function find(num, begin = 0, end = friends.length) {
      const mid = Math.floor((begin + end) / 2)
      const value = friends[mid]
      if (value === num) return true
      if (begin >= end) return false
      if (value < num) return find(num, mid + 1, end)
      return find(num, begin, mid - 1)
  }
  for(let i = 0; i < order.length; i++) {
      const curr = order[i]
      if (find(curr)) res.push(curr)
  }
  return res
};