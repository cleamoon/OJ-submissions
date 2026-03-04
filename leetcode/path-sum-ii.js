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
 * @param {number} targetSum
 * @return {number[][]}
 */
var pathSum = function(root, targetSum) {
    let ans = []
    let path = []
    const find = (node, s = 0) => {
        const ns = s + node.val
        path.push(node.val)
        if (!node.left) {
            if (!node.right) {
                if (ns === targetSum) {
                    ans.push([...path])
                }
            } else {
                find(node.right, ns)
            }
        } else {
            find(node.left, ns)
            if (node.right) {
                find(node.right, ns)
            }
        }
        path.pop()
    }
    find(root)
    return ans
};