func totalNQueens(n int) int {
	var result int
	backtrack(0, n, 0, 0, 0, &result)
	return result
}

func backtrack(row, n, cols, diag1, diag2 int, result *int) {
	if row == n {
		*result++
		return
	}
	
	availablePositions := ^(cols | diag1 | diag2) & ((1 << n) - 1)
	for availablePositions != 0 {
		position := availablePositions & -availablePositions
		availablePositions ^= position
		backtrack(row+1, n, cols|position, (diag1|position)<<1, (diag2|position)>>1, result)
	}
}