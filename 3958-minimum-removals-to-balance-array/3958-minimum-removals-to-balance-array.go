func minRemoval(nums []int, k int) int {
    n := len(nums)

    if n == 1 {
        return 0
    }

    sort.Ints(nums)

    i := 0
    maxLen := 0

    for j := range n {
        for nums[j] > nums[i] * k {
            i++
        }

        if j - i + 1 > maxLen {
            maxLen = j - i + 1
        }
    }

    return n - maxLen
}