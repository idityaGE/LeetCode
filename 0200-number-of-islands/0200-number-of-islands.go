func numIslands(grid [][]byte) int {
	n, m := len(grid), len(grid[0])

	visited := make([][]bool, n)
	for i := range n {
		visited[i] = make([]bool, m)
	}

	var dfs func(int, int)
	dfs = func(row, col int) {
		visited[row][col] = true

		dirs := [][2]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
        for _, d := range dirs {
            nrow, ncol := row+d[0], col+d[1]
			if nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == '1' && !visited[nrow][ncol] {
                dfs(nrow, ncol)
            }
		}
	}

	count := 0

	for row := range n {
		for col := range m {
			if grid[row][col] == '1' && !visited[row][col] {
				dfs(row, col)
				count++
			}
		}
	}

	return count
}