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
 * @return {string[]}
 */
var binaryTreePaths = function(root) {
    let ans = []
    let p = []
    const find = (node) => {
        p.push(node.val)
        if (!node.left) {
            if (!node.right) {
                ans.push(p.join('->'))
            } else {
                find(node.right)
            }
        } else {
            find(node.left)
            if(node.right) {
               find(node.right) 
            }
        }
        p.pop()
    }
    find(root)
    return ans
};