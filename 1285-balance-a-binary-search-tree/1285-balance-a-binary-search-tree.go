/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func balanceBST(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}

	arr := make([]int, 0)
	inorder(&arr, root)

	return constructBST(&arr, 0, len(arr)-1)
}

func constructBST(arr *[]int, l, r int) *TreeNode {
	if l > r {
		return nil
	}

	mid := l + (r-l)/2
	node := &TreeNode{}

	node.Val = (*arr)[mid]

	node.Left = constructBST(arr, l, mid-1)
	node.Right = constructBST(arr, mid+1, r)

	return node
}

func inorder(arr *[]int, node *TreeNode) {
	if node == nil {
		return
	}

	inorder(arr, node.Left)
	*arr = append(*arr, node.Val)
	inorder(arr, node.Right)
}