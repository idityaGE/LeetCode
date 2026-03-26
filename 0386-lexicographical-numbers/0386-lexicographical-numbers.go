func lexicalOrder(n int) []int {
	var res []int

	for i := 1; i <= 9; i++ {
		if i > n {
			break
		}
		dfs(i, n, &res)
	}

	return res
}

func dfs(curr, n int, res *[]int) {
	if curr > n {
		return
	}

	*res = append(*res, curr)

	for i := 0; i <= 9; i++ {
		next := curr*10 + i
		if next > n {
			break
		}
		dfs(next, n, res)
	}
}