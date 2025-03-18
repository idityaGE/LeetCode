func longestNiceSubarray(nums []int) int {
    n := len(nums)
    maxLength := 1
    left := 0
    usedBits := 0

    for right := 0; right < n; right++ {
        for (usedBits & nums[right]) != 0 {
            usedBits ^= nums[left]
            left++
        }

        usedBits |= nums[right]
        if right-left+1 > maxLength {
            maxLength = right - left + 1
        }
    }

    return maxLength
}