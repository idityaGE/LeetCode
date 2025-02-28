func shortestCommonSupersequence(str1, str2 string) string {
    ans := ""
    lcs := findLCS(str1, str2)

    i, j := 0, 0

    for _, c := range lcs {
        for i < len(str1) && str1[i] != byte(c) {
            ans += string(str1[i])
            i++
        }
        for j < len(str2) && str2[j] != byte(c) {
            ans += string(str2[j])
            j++
        }

        ans += string(c)
        i++
        j++
    }

    ans += str1[i:] + str2[j:]

    return ans
}

func findLCS(str1, str2 string) string {
    len1, len2 := len(str1), len(str2)

    // Initialize a 2D slice
    dp := make([][]string, len1+1)
    for i := range dp {
        dp[i] = make([]string, len2+1)
    }

    // Compute LCS using DP
    for i := 1; i <= len1; i++ {
        for j := 1; j <= len2; j++ {
            if str1[i-1] == str2[j-1] {
                dp[i][j] = dp[i-1][j-1] + string(str1[i-1])
            } else {
                if len(dp[i][j-1]) > len(dp[i-1][j]) {
                    dp[i][j] = dp[i][j-1]
                } else {
                    dp[i][j] = dp[i-1][j]
                }
            }
        }
    }

    return dp[len1][len2]
}

