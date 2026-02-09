func sortedListToBST(head *ListNode) *TreeNode {
    if head == nil {
        return nil
    }
    if head.Next == nil {
        return &TreeNode{Val: head.Val}
    }
    
    var prev *ListNode
    slow, fast := head, head
    for fast != nil && fast.Next != nil {
        prev = slow
        slow = slow.Next
        fast = fast.Next.Next
    }
    
    // Disconnect left half
    prev.Next = nil
    
    node := &TreeNode{Val: slow.Val}
    node.Left = sortedListToBST(head)
    node.Right = sortedListToBST(slow.Next)
    
    return node
}