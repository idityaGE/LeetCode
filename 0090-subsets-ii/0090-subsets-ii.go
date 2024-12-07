func subsetUni(arr []int, subsets *[][]int, subset []int, index int) {
	// copy of the current subset
	temp := make([]int, len(subset))
	copy(temp, subset)
	*subsets = append(*subsets, temp)

	for i := index; i < len(arr); i++ {
		// Skip duplicates
		if i > index && arr[i] == arr[i-1] {
			continue
		}

		subset = append(subset, arr[i])
		subsetUni(arr, subsets, subset, i+1)
		
		subset = subset[:len(subset)-1]
	}
}

func subsetsWithDup(arr []int) [][]int {
	var subsets [][]int
	var subset []int

	// Sort the array to handle duplicates
	sort.Ints(arr)
	subsetUni(arr, &subsets, subset, 0)

	return subsets
}