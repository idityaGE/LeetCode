func numberOfSubarrays(nums []int, k int) int {
    return atMost(nums, k) - atMost(nums, k - 1)
}
func atMost(nums []int, goal int) int {
    if goal < 0 {
        return 0
    }
    cnt,sum, l := 0, 0, 0

    for r:=0; r < len(nums); r++ {
        sum += nums[r] % 2
        for sum > goal {
            sum -= nums[l] % 2
            l += 1
        }
        cnt += r - l + 1
    }
    return cnt
}