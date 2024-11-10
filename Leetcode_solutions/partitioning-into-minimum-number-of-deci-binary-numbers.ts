function minPartitions(n: string): number {
    return Math.max(...[...n].map(e => parseInt(e)))
};