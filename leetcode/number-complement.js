/**
 * @param {number} num
 * @return {number}
 */
var findComplement = function(num) {
  let b = 1
  while (b - 1 < num) {
      b *= 2
  }
  return b - 1 - num
};