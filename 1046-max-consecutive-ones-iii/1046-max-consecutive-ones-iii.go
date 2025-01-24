func longestOnes(nums []int, k int) int {
    maxlen, zero, l, r := 0, 0, 0, 0

    for r < len(nums) {
        if nums[r] == 0 {
            zero += 1
        }

        if zero > k {
            if nums[l] == 0 {
                zero -= 1
            }
            l += 1
        }

        if zero <= k {
            maxlen = max(maxlen, r-l+1)
        }

        r += 1
    }

    return maxlen
}