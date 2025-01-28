func atMost(nums []int, goal int) int {
    if goal < 0 {
        return 0
    }
    cnt,sum, l := 0, 0, 0

    for r:=0; r < len(nums); r++ {
        sum += nums[r]
        for sum > goal {
            sum -= nums[l]
            l += 1
        }
        cnt += r - l + 1
    }
    return cnt
}

func numSubarraysWithSum(nums []int, goal int) int {
    return atMost(nums, goal) - atMost(nums, goal - 1)
}