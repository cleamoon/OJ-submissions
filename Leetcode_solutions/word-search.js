/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    const len = word.length
    const width = board.length
    const height = board[0].length

    function backtrack(i, j, n) {
        if (n === len) return true
        if (
            i < 0 || 
            i >= width || 
            j < 0 || 
            j >= height || 
            board[i][j] === 0 ||
            board[i][j] !== word[n]
        ) {
            return false
        }

        const curr = board[i][j]
        board[i][j] = 0

        const res = 
            backtrack(i + 1, j, n + 1) ||
            backtrack(i - 1, j, n + 1) ||
            backtrack(i, j + 1, n + 1) ||
            backtrack(i, j - 1, n + 1)

        board[i][j] = curr

        return res
    }

    for (let i = 0; i < width; i++) {
        for (let j = 0; j < height; j++) {
            if (backtrack(i, j, 0)) {
                return true
            }
        }
    }

    return false
};