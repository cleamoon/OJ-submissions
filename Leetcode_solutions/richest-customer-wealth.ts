function maximumWealth(accounts: number[][]): number {
    let ans = 0
    accounts.forEach(account => {
        const sum = account.reduce((e, acc) => {
            return e + acc
        }, 0)
        ans = ans > sum ? ans : sum
    })
    return ans
};