func subsetXORSum(nums []int) int {
	allXORsum := 0
	noOfSub := 1 << len(nums)
	for i := range noOfSub {
		subXOR := 0
		for j, num := range nums {
			if (1 << j) & i != 0 {
				subXOR ^= num
			}
		}
		allXORsum += subXOR
	}
    return allXORsum
}