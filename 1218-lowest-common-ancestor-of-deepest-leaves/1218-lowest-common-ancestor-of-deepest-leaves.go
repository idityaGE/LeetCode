func lcaDeepestLeaves(root *TreeNode) *TreeNode {
	_, lca := dfs(root)
	return lca
}

func dfs(root *TreeNode) (int, *TreeNode) {
	if root == nil {
		return 0, nil
	}

	leftDepth, leftLCA := dfs(root.Left)
	rightDepth, rightLCA := dfs(root.Right)

	if leftDepth > rightDepth {
		return leftDepth + 1, leftLCA
	}
	if leftDepth < rightDepth {
		return rightDepth + 1, rightLCA
	}
	return leftDepth + 1, root
}