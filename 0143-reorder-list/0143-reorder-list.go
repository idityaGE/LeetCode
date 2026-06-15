/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reorderList(head *ListNode)  {
    left := head
    

    for left.Next != nil && left.Next.Next != nil  {
        var prev *ListNode = nil
        right := left
        
        for right.Next != nil {
            prev = right
            right = right.Next
        }

        leftNext := left.Next

        left.Next = prev.Next
        right.Next = leftNext
        prev.Next = nil


        left = leftNext
    }
}