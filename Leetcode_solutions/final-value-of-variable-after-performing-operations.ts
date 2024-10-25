function finalValueAfterOperations(operations: string[]): number {
    let x = 0
    for (let i = 0; i < operations.length; i++) {
        const op = operations[i]
        if (op === "++X" || op === "X++") {
            x += 1
        }
        if (op === "--X" || op === "X--") {
            x -= 1
        }
    }
    return x
};