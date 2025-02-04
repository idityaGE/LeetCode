func maxAscendingSum(nums []int) int {
	n := len(nums)

	if n == 0 {
		return 0
	}
	if n == 1 {
		return nums[0]
	}

	sum, maxSum := nums[0], nums[0]

	for i := 1; i < len(nums); i++ {
		if nums[i-1] >= nums[i] {
			sum = 0
		}
		sum += nums[i]
		maxSum = max(maxSum, sum)
	}

	return maxSum
}