function evaluateTree(root: TreeNode | null): boolean {
    if (!root.left) return root.val > 0
    if (root.val === 2) {
        return (evaluateTree(root.left) || evaluateTree(root.right))
    } else if (root.val === 3) {
        return (evaluateTree(root.left) && evaluateTree(root.right))
    }
};