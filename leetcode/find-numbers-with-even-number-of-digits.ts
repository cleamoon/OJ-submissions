function findNumbers(nums: number[]): number {
  return nums.reduce((acc, e) => {
      if (e.toString().length % 2 === 0) return acc + 1
      else return acc
  }, 0)
};
