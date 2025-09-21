/**
 * @param {string} text
 * @param {string} brokenLetters
 * @return {number}
 */
var canBeTypedWords = function(text, brokenLetters) {
        const words = text.split(' ')
        const brklts = brokenLetters.split('')
        let ans = 0
        words.forEach(w => {
            let found = false
            const chs = w.split('')
            for (const i in chs) {
                if (brklts.includes(chs[i])) {
                    found = true
                    break
                }
            }
            if (!found) ans++
        })
        return ans
};