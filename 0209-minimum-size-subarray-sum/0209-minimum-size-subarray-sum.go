func minSubArrayLen(target int, nums []int) int {
    left, right := 0, 0 

    ans := len(nums) + 1
    sum := 0
    for right < len(nums) {
        sum += nums[right] 
        for sum >= target {
            if right-left+1 < ans {
                ans = right - left + 1 
            }
            sum -= nums[left]
            left++
        }
        right++
    }

    if ans == len(nums) + 1 {
        return 0
    }

    return ans
}