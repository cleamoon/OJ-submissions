function luckyNumbers(matrix: number[][]): number[] {
    let min_row: [number, number][] = []
    for (let i = 0; i < matrix.length; i++) {
        let id
        let min = Infinity
        for (let j = 0; j < matrix[i].length; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j]
                id = j
            }
        }
        min_row.push([min, id])
    }
    let res: number[] = []
    for (let k = 0; k < min_row.length; k++) {
        let j = min_row[k][1]
        let max = 0
        for (let i = 0; i < matrix.length; i++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j]
            }
        }
        if (max === min_row[k][0]) {
            res.push(max)
        }
    }
    return res
};
