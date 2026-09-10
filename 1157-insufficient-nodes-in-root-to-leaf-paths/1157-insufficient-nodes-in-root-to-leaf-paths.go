 func sufficientSubset(root *TreeNode, limit int) *TreeNode {
       return solve(root, limit, 0)
   }

   func solve(node *TreeNode, limit int, sum int) *TreeNode {
       if node == nil {
           return nil
       }

       sum += node.Val

       if node.Left == nil && node.Right == nil {
           if sum < limit {
               return nil
           }
           return node
       }

       node.Left = solve(node.Left, limit, sum)
       node.Right = solve(node.Right, limit, sum)

       if node.Left == nil && node.Right == nil {
           return nil
       }

       return node
   }