function maxKDistinct(nums: number[], k: number): number[] {
  const uniqueArray = Array.from(new Set(nums))
  const sortedUnique = uniqueArray.sort((a, b) => {
      if (a > b) return -1
      else if (a < b) return 1
      else return 0
  })
  return sortedUnique.slice(0, k)
};