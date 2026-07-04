from dataclasses import dataclass


@dataclass
class TreeNode:
    val: int
    left: "TreeNode | None" = None
    right: "TreeNode | None" = None


def build_tree(inorder, postorder):
    if not inorder or not postorder:
        return None

    root_val = postorder[-1]
    root = TreeNode(root_val)

    mid = inorder.index(root_val)

    left_inorder = inorder[:mid]
    right_inorder = inorder[mid + 1 :]

    left_size = len(left_inorder)

    left_postorder = postorder[:left_size]
    right_postorder = postorder[left_size:-1]

    root.left = build_tree(left_inorder, left_postorder)
    root.right = build_tree(right_inorder, right_postorder)

    return root


in_order_str = "T, b, H, V, h, 3, o, g, P, W, F, L, u, A, f, G, r, m, 1, x, J, 7, w, e, 0, i, Q, Y, n, Z, 8, K, v, q, k, 9, y, 5, C, N, B, D, 2, 4, U, l, c, p, I, E, M, a, j, 6, S, R, O, X, s, d, z, t"
post_order_str = "T, V, H, o, 3, h, P, g, b, F, f, A, u, m, r, 7, J, x, e, w, 1, Y, Q, i, 0, Z, n, G, L, K, y, 9, k, q, v, N, D, B, C, 5, 4, c, l, U, 2, 8, E, I, R, S, 6, j, d, s, X, O, a, M, p, W, t, z"

in_order = in_order_str.split(", ")
post_order = post_order_str.split(", ")

root = build_tree(in_order, post_order)


def find_deepest_path(root: TreeNode):
    if not root:
        return []

    left_path = find_deepest_path(root.left)
    right_path = find_deepest_path(root.right)

    if len(left_path) > len(right_path):
        return [root.val] + left_path
    else:
        return [root.val] + right_path


deepest_path = find_deepest_path(root)

deepest_path_str = "".join(deepest_path)

print(deepest_path_str)
