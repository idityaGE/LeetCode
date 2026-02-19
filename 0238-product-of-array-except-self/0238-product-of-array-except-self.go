func productExceptSelf(nums []int) []int {
    n := len(nums)

    if n == 2 {
        return []int{nums[1], nums[0]}
    }

    pre := make([]int, n)
    suf := make([]int, n)

    pre[0] = nums[0]
    suf[n - 1] = nums[n - 1]

    for i := 1; i < n; i++ {
        pre[i] = nums[i] * pre[i -1]
    }

    for i := n - 2; i >= 0; i-- {
        suf[i] = nums[i] * suf[i + 1]
    }

    // fmt.Println(pre)
    // fmt.Println(suf)

    res := make([]int, n)

    res[0] = suf[1]
    res[n - 1] = pre[n - 2]

    for i := 1; i < n - 1; i++ {
        res[i] = pre[i - 1] * suf[i + 1]
    }

    return res
}
