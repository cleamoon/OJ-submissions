function findPermutationDifference(s: string, t: string): number {
    let li: number[][] = []
    for (let i = 0; i < 26; i++) {
        li.push([])
    }
    const acode = 'a'.charCodeAt(0)
    for (let i = 0; i < s.length; i++) {
        li[s[i].charCodeAt(0) - acode].push(i)
        li[t[i].charCodeAt(0) - acode].push(i)
    }
    let ans = 0
    for (let i = 0; i < 26; i++) {
        const e = li[i]
        if (e.length === 0) continue
        ans += Math.abs(e[0] - e[1])
    }
    return ans
};