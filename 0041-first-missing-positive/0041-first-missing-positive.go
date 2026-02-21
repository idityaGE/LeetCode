func firstMissingPositive(nums []int) int {
	n := len(nums)

	for i := 0; i < n; i++ {
		// Swap numbers to their correct positions
		for nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i] {
			target := nums[i] - 1
			nums[target], nums[i] = nums[i], nums[target]
		}
	}

	// Determine the first missing positive number
	for i := 0; i < n; i++ {
		if nums[i] != i+1 {
			return i + 1
		}
	}

	return n + 1 // If all numbers 1 to n are present, return n+1
}