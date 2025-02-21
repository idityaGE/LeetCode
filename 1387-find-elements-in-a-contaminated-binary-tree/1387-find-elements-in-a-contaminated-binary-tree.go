/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type FindElements struct {
    Value map[int]bool
}

func recover(root *TreeNode, data *FindElements, parent, val int) {
    if root == nil {
        return
    }
    
    data.Value[val] = true
        
    recover(root.Left, data, val, (2 * val) + 1)
    recover(root.Right, data, val, (2 * val)+ 2)
}

func Constructor(root *TreeNode) FindElements {
    var data FindElements
    data.Value = make(map[int]bool)
    recover(root, &data, 0, 0)
    return data
}


func (this *FindElements) Find(target int) bool {
    if this.Value[target] == true {
        return true
    }
    return false
}


/**
 * Your FindElements object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Find(target);
 */