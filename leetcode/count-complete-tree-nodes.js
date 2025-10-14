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
var countNodes = function(root) {
    let ans = 0
    function calc(root) {
        if (!root) return
        ans += 1
        if (root.left) {
            calc(root.left)
        }
        if (root.right) {
            calc(root.right)
        }

    }
    calc(root)
    return ans
};