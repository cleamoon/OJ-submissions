function largestLocal(grid: number[][]): number[][] {
    const width = grid.length
    const height = grid[0].length

    const res: number[][] = []

    for (let i = 1; i < width - 1; i++) {
        const row: number[] = []
        for (let j = 1; j < height - 1; j++) {
            let max = -Infinity
            for (let p = -1; p <= 1; p++) {
                for (let q = -1; q <= 1; q++) {
                    max = Math.max(max, grid[i + p][j + q])
                }
            }
            row.push(max)
        }
        res.push(row)
    }
    return res
};