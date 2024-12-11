func maxSubArray(nums []int) int {
	sum := 0
	max_ele := math.MinInt
	for i, _ := range nums {
        sum += nums[i]
        max_ele = max(sum, max_ele)
        if sum < 0 {
            sum = 0
        }
	}
    return max_ele
}