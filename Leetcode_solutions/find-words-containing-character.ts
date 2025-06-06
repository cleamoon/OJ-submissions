function findWordsContaining(words: string[], x: string): number[] {
    let res: number[] = []
    words.forEach((word, index) => {
        if (word.includes(x)) {
            res.push(index)
        }
    })
    return res
};
