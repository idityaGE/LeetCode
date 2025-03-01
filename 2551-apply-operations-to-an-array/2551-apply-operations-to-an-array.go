func applyOperations(nums []int) []int {

	for i := 0; i < len(nums)-1; i++ {
		if nums[i] == nums[i+1] {
			nums[i] *= 2
			nums[i+1] = 0
		}
	}

	pos := 0

    for _, num := range nums {
        if num != 0 {
            nums[pos] = num
            pos++
        }
    }

    for i :=  pos; i < len(nums); i++ {
        nums[i] = 0   
    }

	return nums
}