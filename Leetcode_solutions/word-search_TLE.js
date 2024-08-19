/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    let map = []
    const len = word.length
    const width = board.length
    const height = board[0].length
    for(let i = 0; i < len; i++) {
        const ch = word[i]
        let new_map = []
        for (let j = 0; j < width; j++) {
            for (let k = 0; k < height; k++) {
                const loc = board[j][k]
                if (ch === loc) {
                    if (i === 0) {
                        new_map.push([[j, k]])
                    } else {
                        for(let m = 0; m < map.length; m++) {
                            const li = map[m]
                            const li_len = li.length
                            const last = li[li_len - 1]
                            const diff = Math.abs(last[0] - j) + Math.abs(last[1] - k)
                            if (diff !== 1) {
                                continue
                            }
                            let exist = false
                            for(let l = 0; l < li_len; l++) {
                                if (li[l][0] === j && li[l][1] === k) {
                                    exist = true
                                    continue
                                }
                            }
                            if (!exist) {
                                new_map.push([...li, [j, k]])
                            }
                        }
                    }
                }
            }
        }
        if (new_map.length === 0) {
            return false
        } else if (new_map[0].length === len) {
            return true
        } else if (new_map[0].length > len) {
            return false
        }
        map = new_map
    }
    return true
};