/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    let array = path.split('/')
    let res = []
    array.forEach((item) => {
        if (item === "..") {
            res.pop()
        } else if (item !== "." && item !== "") {
            res.push(item)
        }
    })
    return "/" + res.join("/")
};