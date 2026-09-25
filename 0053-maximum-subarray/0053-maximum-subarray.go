func maxSubArray(nums []int) int {
    curr := nums[0]
    best := nums[0]

    for i := 1; i < len(nums); i++ {
        curr = max(curr+nums[i], nums[i])
        best = max(curr, best)
    }

    return best
}

func max(a, b int) int {
    if a >= b {
        return a
    }
    return b
}