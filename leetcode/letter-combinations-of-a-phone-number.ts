function letterCombinations(digits: string): string[] {
    const d2l = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz"
    }
    let res: string[] = []
    digits.split('').forEach(d => {
        const ls = d2l[d].split('')
        if (res.length === 0) {
            ls.forEach(l => {
                res.push(l)
            })
        } else {
            let new_res: string[] = []
            res.forEach(r => {
                ls.forEach(l => {
                    new_res.push(`${r}${l}`)
                })
            })
            res = new_res
        }
    })
    return res
};