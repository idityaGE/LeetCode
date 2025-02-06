func tupleSameProduct(nums []int) int {
	freq := make(map[int]int)
	cnt := 0

	for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			product := nums[i] * nums[j]
			freq[product]++
		}
	}

	for _, n := range freq {
		if n > 1 {
			cnt += 8 * (n * (n - 1) / 2)
		}
	}
    
	return cnt
}
