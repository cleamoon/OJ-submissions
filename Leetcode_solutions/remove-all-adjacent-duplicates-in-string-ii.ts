function removeDuplicates(s: string, k: number): string {
    if (s.length < k) return s
    let ans = [...s]
    for (let i = 0; i < ans.length - 1; i++) {
        if (ans.length < k) break
        const curr = ans[i]
        let found = true
        let j = 1;
        for (; j < k; j++) {
            if (ans[i + j] != curr || i + j === ans.length) {
                found = false;
                break
            }
        }
        if (!found) {
            i += j - 1
            continue
        } else {
            ans.splice(i, k)
            i -= k
        }
    }

    return ans.join('')
};