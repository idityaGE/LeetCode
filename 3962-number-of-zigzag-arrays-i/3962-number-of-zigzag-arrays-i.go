func zigZagArrays(n int, l int, r int) int {
	const MOD int = 1000000007

	m := r - l + 1

	dp := make([]int, m)
	for i := 0; i < m; i++ {
		dp[i] = 1
	}

	for length := 2; length <= n; length++ {

		for left, right := 0, m-1; left < right; left, right = left+1, right-1 {
			dp[left], dp[right] = dp[right], dp[left]
		}

		pref := 0

		for i := 0; i < m; i++ {
			old := dp[i]

			dp[i] = pref

			pref += old
			pref %= MOD
		}
	}

	ans := 0

	for _, x := range dp {
		ans += x
		ans %= MOD
	}

	return (ans * 2) % MOD
}