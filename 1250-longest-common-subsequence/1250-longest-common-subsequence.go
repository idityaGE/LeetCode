func longestCommonSubsequence(text1 string, text2 string) int {
	dp := make([]int, len(text1))

	longest := 0

	for _, c := range text2 {
		currLen := 0
		for i, val := range dp {
			if currLen < val {
				currLen = val
			} else if c == rune(text1[i]) {
				dp[i] = currLen + 1
				longest = max(longest, currLen+1)
			}
		}
	}

	return longest
}