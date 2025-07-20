class Solution {
    private boolean shouldDelete(TreeNode node, int target) {
        boolean deleteLeft = node.left == null || shouldDelete(node.left, target);
        boolean deleteRight = node.right == null || shouldDelete(node.right, target);
        boolean deleteSelf = node.val == target && deleteLeft && deleteRight;
        if (deleteLeft) node.left = null;
        if (deleteRight) node.right = null;
        if (deleteSelf) return true;
        else return false;
    }

    public TreeNode removeLeafNodes(TreeNode root, int target) {
        if (shouldDelete(root, target)) return null;
        return root;
    }
}
