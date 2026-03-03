/**
 * @param {string} sentence
 * @return {string}
 */
var toGoatLatin = function(sentence) {
    const words = sentence.split(' ')
    const new_words = []
    for (let i = 0; i < words.length; i++) {
        const word = words[i]
        if (['a', 'e', 'i', 'o', 'u'].includes(word[0].toLowerCase())) {
            let new_word = `${word}ma` + 'a'.repeat(i + 1)
            new_words.push(new_word)
        } else {
            let new_word = word.slice(1)
            new_word = `${new_word}${word[0]}ma` + 'a'.repeat(i + 1)
            new_words.push(new_word)
        }
    }
    return new_words.join(' ')
};