function kidsWithCandies(candies: number[], extraCandies: number): boolean[] {
    const max = candies.reduce((acc, n) => {
        if (n > acc) return n
        return acc
    }, -Infinity)
    const res = candies.map(e => {
        if (e + extraCandies >= max) return true
        return false
    })
    return res
};