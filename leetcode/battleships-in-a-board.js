/**
 * @param {character[][]} board
 * @return {number}
 */
var countBattleships = function(board) {
    let visited = []
    for (let i = 0; i < board.length; i++) {
        visited.push(Array.from({length: board[0].length}).map(() => false))
    }
    let ans = 0
    for (let i = 0; i < board.length; i++) {
        for (let j = 0; j < board[0].length; j++) {
            if (visited[i][j]) continue
            visited[i][j] = true
            if (board[i][j] == "X") {
                for (let k = 1; k + i < board.length; k++) {
                    if (board[i + k][j] == "X") {
                        visited[i + k][j] = true
                    } else {
                        break
                    }
                }
                for (let k = 1; k + j < board[0].length; k++) {
                    if (board[i][j + k] == "X") {
                        visited[i][j + k] = true
                    } else {
                        break
                    }
                }
                ans += 1
            }
        }
    }
    return ans
};