/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function reverseOddLevels(root: TreeNode | null): TreeNode | null {
  let level = 0
  let lst = [root]
  let new_lst = []
  while (lst.length !== 0) {
      new_lst = []
      if (!lst[0].left) break
      lst.forEach((node) => {
          new_lst.push(node.left)
          new_lst.push(node.right)
      })
      if (level % 2 === 0) {
          const vals = new_lst.map(node => node.val).reverse()
          for(let i = 0; i < new_lst.length; i++) {
              new_lst[i].val = vals[i]
          }
      }
      lst = new_lst
      level += 1
  }
  return root
};