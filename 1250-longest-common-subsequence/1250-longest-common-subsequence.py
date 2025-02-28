class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [0] * len(text1)

        longest = 0

        for c in text2:
            currLen = 0
            for i, val in enumerate(dp):
                if currLen < val:
                    currLen = val
                elif c==text1[i]:
                    dp[i] = currLen + 1
                    longest = max(currLen+1, longest)
                
        return longest