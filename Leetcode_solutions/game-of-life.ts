/**
 Do not return anything, modify board in-place instead.
 */
function gameOfLife(board: number[][]): void {
    const height = board.length
    const width = board[0].length

    let new_board: number[][] = []
    for (let i = 0; i < height; i++) {
        new_board.push([])
        for (let j = 0; j < width; j++) {
            new_board[i].push(board[i][j]);
        }
    }

    for (let i = 0; i < height; i++) {
        for (let j = 0; j < width; j++) {
            let neigh = 0
            for (let m = i - 1; m <= i + 1; m++) {
                for (let n = j - 1; n <= j + 1; n++) {
                    if (m < 0 || m >= height || n < 0 || n >= width || (m === i && n === j)) continue
                    if (board[m][n] === 1) {
                        neigh += 1
                    }
                }
            }
            if (board[i][j] === 1) {
                if (neigh < 2 || neigh > 3) {
                    new_board[i][j] = 0
                } else {
                    new_board[i][j] = 1
                }
            } else {
                if (neigh === 3) {
                    new_board[i][j] = 1
                } else {
                    new_board[i][j] = 0
                }
            }
        }
    }

    for (let i = 0; i < height; i++) {
        for (let j = 0; j < width; j++) {
            board[i][j] = new_board[i][j]
        }
    }
};