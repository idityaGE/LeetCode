/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func preorderTraversal(root *TreeNode) []int {
    ans := []int{}

    var dfs func(*TreeNode)
    dfs = func(node *TreeNode) {
        if node == nil {
            return
        }

        ans = append(ans, node.Val)

        dfs(node.Left)
        dfs(node.Right)
    }

    dfs(root)

    return ans
}