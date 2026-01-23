function dist(pa: number[], pb: number[]) {
    return Math.sqrt((pa[0] - pb[0]) * (pa[0] - pb[0]) + (pa[1] - pb[1]) * (pa[1] - pb[1]))
}

function isTriangle(d1, d2, d3) {
    const arr = [d1, d2, d3]
    arr.sort()
    return d1 + d2 > d3
}

function area(d1, d2, d3) {
    const s = (d1 + d2 + d3) / 2
    return Math.sqrt(s * (s - d1) * (s - d2) * (s - d3))
}

function largestTriangleArea(points: number[][]): number {
    let ans = -1.0

    for (let i = 0; i < points.length - 2; i++) {
        for (let j = i + 1; j < points.length - 1; j++) {
            for (let k = j + 1; k < points.length; k++) {
                const p1 = points[i]
                const p2 = points[j]
                const p3 = points[k]
                const d1 = dist(p1, p2)
                const d2 = dist(p2, p3)
                const d3 = dist(p1, p3)
                if (!isTriangle(d1, d2, d3)) continue
                const a = area(d1, d2, d3)
                if (a > ans) ans = a
            }
        }
    }
    return ans
};