/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root1
 * @param {TreeNode} root2
 * @return {boolean}
 */
var leafSimilar = function (root1, root2) {
    const treeToArray = (root, arr = []) => {
        if (!root) return arr
        if (!root.left && !root.right) {
            return [...arr, root.val]
        }
        return treeToArray(root.right, treeToArray(root.left, arr))
    }
    const arr1 = treeToArray(root1)
    const arr2 = treeToArray(root2)
    if (arr1.length !== arr2.length) return false
    for (let i = 0; i < arr1.length; i++) {
        if (arr1[i] !== arr2[i]) return false
    }
    return true
};