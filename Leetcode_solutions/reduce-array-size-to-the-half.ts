function minSetSize(arr: number[]): number {
    let numToOccurs = new Map()
    for (let i = 0; i < arr.length; i++) {
        const num = arr[i]
        if (numToOccurs.has(num)) {
            numToOccurs.set(num, numToOccurs.get(num) + 1)
        } else {
            numToOccurs.set(num, 1)
        }
    }
    const occurs = [...numToOccurs].sort((a, b) => {
        if (a[1] < b[1]) return 1
        if (a[1] > b[1]) return -1
        return 0
    })

    let half = Math.ceil(arr.length / 2)

    let ans = 0;

    for (let i = 0; i < occurs.length; i++) {
        half -= occurs[i][1]
        ans += 1
        if (half <= 0) {
            return ans
        }
    }
    return ans
};