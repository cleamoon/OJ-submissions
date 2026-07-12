/**
 * @param {number} area
 * @return {number[]}
 */
var constructRectangle = function(area) {
    let i = Math.floor(Math.sqrt(area))
    if (i * i < area) i += 1
    while (i <= area) {
        const j = Math.floor(area / i)
        if (j * i === area) {
            return [i, j]
        } else {
            i += 1
        }
    }
    return [area, 1]
};
