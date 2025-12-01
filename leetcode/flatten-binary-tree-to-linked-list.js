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
 * @return {void} Do not return anything, modify root in-place instead.
 */
var flatten = function(root) {
    const getRightest = (node) => {
        if (!node.right) return node
        else return getRightest(node.right)
    }
    const comp = (node) => {
        if (!node) return
        if (!node.left) return comp(node.right)
        const right = node.right
        node.right = node.left
        const rightest = getRightest(node)
        rightest.right = right
        node.left = null
        return comp(node.right)
    }
    return comp(root)
};