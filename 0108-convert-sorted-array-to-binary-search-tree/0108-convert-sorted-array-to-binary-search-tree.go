/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sortedArrayToBST(nums []int) *TreeNode {
	return construct(0, len(nums)-1, nums)
}

func construct(l, r int, arr []int) *TreeNode {
	if l > r {
		return nil
	}

	mid := l + (r-l)/2

	node := &TreeNode{}

	node.Val = arr[mid]

	node.Left = construct(l, mid-1, arr)
	node.Right = construct(mid+1, r, arr)

	return node
}