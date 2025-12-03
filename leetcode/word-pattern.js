/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */

var wordPattern = function(pattern, s) {
  let pts = {}
  let stp = {}
  const pa = pattern.split('')
  const sa = s.split(' ')
  if (pa.length !== sa.length) return false
  for (let i = 0; i < pa.length; i++) {
      const p = pa[i]
      const cs = sa[i]
      const fs = cs.split('').join('-')
      if (pts[p] && pts[p] !== cs) return false
      if (stp[fs] && stp[fs] !== p) return false
      pts[p] = cs
      stp[fs] = p
  }
  return true
};