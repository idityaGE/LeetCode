func maxAbsoluteSum(nums []int) int {
	maxPrefixSum := 0
	minPrefixSum := 0

	prefix := 0
	for _, num := range nums {
		prefix += num
		maxPrefixSum = max(prefix, maxPrefixSum)
		minPrefixSum = min(prefix, minPrefixSum)
	}
	return (maxPrefixSum - minPrefixSum)
}