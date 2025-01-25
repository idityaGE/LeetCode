func totalFruit(fruits []int) int {
	mp := make(map[int]int)
	maxLen := 0
	left := 0

	for r := 0; r < len(fruits); r++ {
		mp[fruits[r]]++

		if len(mp) > 2 {
			mp[fruits[left]]--
			if mp[fruits[left]] == 0 {
				delete(mp, fruits[left])
			}
			left++
		}

		if len(mp) <= 2 {
			maxLen = max(maxLen, r-left+1)
		}
	}
	return maxLen
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}