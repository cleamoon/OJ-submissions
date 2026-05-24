/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var averageOfSubtree = function(root) {
    let ans = 0
    const aver = (node) => {
        console.log(node.val)
        if (!node) return [0, 0]
        const v = node.val
        if (!node.left) {
            if (!node.right) {
                ans ++
                return [node.val, 1]
            } else {
                const [rv, rc] = aver(node.right)
                if (rc === 0) return [0, 0]
                if (Math.floor((rv + v) / (rc + 1)) === v) ans++
                return [rv + v, rc + 1]
            }
        } else {
            if (!node.right) {
                const [lv, lc] = aver(node.left)
                if (lc === 0) return [0, 0]
                if (Math.floor((lv + v) / (lc + 1)) === v) ans++
                return [lv + v, lc + 1]
            } else {
                const [lv, lc] = aver(node.left)
                const [rv, rc] = aver(node.right)
                const sum = lv + rv
                const cnt = lc + rc
                if (cnt === 0) return [0, 0]
                if (Math.floor((sum + v) / (cnt + 1)) === v) ans++
                return [sum + v, cnt + 1]
            }
        }
    }
    aver(root)
    return ans
};