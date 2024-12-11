func findMin(nums []int) int {
	low, high := 0, len(nums)-1
	ans := nums[0]

	for low <= high {
		mid := low + (high-low)/2

		if nums[low] <= nums[high] {
			ans = min(ans, nums[low])
			break
		}
		if nums[low] <= nums[mid] {
			ans = min(ans, nums[low])
			low = mid + 1
		} else {
			ans = min(ans, nums[high])
			high = mid - 1
		}
	}

	return ans
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}