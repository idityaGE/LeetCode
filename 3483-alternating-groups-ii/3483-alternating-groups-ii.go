func numberOfAlternatingGroups(colors []int, k int) int {
	colors = append(colors, colors[:k-1]...)
	cnt := 0

	for left, right := 0, 0; right < len(colors); right++ {
		if right > 0 && colors[right] == colors[right-1] {
			left = right
		}
		if right-left+1 >= k {
			cnt++
		}
	}

	return cnt
}