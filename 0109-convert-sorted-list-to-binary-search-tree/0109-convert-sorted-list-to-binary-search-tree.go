/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sortedListToBST(head *ListNode) *TreeNode {
    if head == nil {
        return nil
    }

	arr := LlToArr(head)

	return construct(arr, 0, len(arr)-1)
}

func construct(arr []int, l, r int) *TreeNode {
	if l > r {
		return nil
	}

	mid := l + (r-l)/2
	node := &TreeNode{}

	node.Val = arr[mid]

	node.Left = construct(arr, l, mid-1)
	node.Right = construct(arr, mid+1, r)

	return node
}

func LlToArr(head *ListNode) []int {
	arr := make([]int, 0)

	temp := head

	for temp != nil {
		arr = append(arr, temp.Val)
		temp = temp.Next
	}

	return arr
}