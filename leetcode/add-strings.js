/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function(num1, num2) {
    let arr1 = num1.split('').map(Number).toReversed()
    let arr2 = num2.split('').map(Number).toReversed()
    let i = 0
    let ans = []
    let c = false
    while(i < arr1.length || i < arr2.length || c) {
        const v1 = i < arr1.length ? arr1[i] : 0
        const v2 = i < arr2.length ? arr2[i] : 0
        let nv = v1 + v2 + (c ? 1 : 0)
        if (nv > 9) {
            c = true
            nv %= 10
        } else {
            c = false
        }
        ans.push(nv)
        i += 1
    }
    ans.reverse()
    const ansStr = ans.join('')
    return ansStr
};