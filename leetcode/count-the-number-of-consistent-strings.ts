function countConsistentStrings(allowed: string, words: string[]): number {
    let ans = 0;
    for (let i = 0; i < words.length; i++) {
        const word = words[i]
        let cons = true
        for (let j = 0; j < word.length; j++) {
            if (!allowed.includes(word[j])) {
                cons = false
                break
            }
        }
        if (cons) {
            ans++
        }
    }
    return ans
};
