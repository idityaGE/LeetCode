func productExceptSelf(nums []int) []int {
	n := len(nums)
	output := make([]int, n)

	output[0] = 1
	for i := 1; i < n; i++ {
		output[i] = output[i-1] * nums[i-1]
	}

	right := 1
	for i := n - 1; i >= 0; i-- {
		output[i] *= right
		right *= nums[i]
	}

	return output
}