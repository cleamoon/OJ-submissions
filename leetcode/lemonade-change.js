/**
 * @param {number[]} bills
 * @return {boolean}
 */
var lemonadeChange = function (bills) {
    let n5 = 0, n10 = 0
    for (let i = 0; i < bills.length; i++) {
        const b = bills[i]
        if (b == 5) {
            n5++
        } else if (b == 10) {
            if (n5 == 0) return false
            n5--
            n10++
        } else if (b == 20) {
            if (n5 == 0) return false
            if (n10 == 0) {
                if (n5 < 3) return false
                n5 -= 3
            } else {
                n10--
                n5--
            }
        }
    }

    return true
};