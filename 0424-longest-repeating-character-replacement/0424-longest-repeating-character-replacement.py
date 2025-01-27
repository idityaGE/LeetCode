class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        max_len = 0
        max_freq = 0
        l = 0
        freq_hash = {}

        for r in range(len(s)):
            freq_hash[s[r]] = freq_hash.get(s[r], 0) + 1
            max_freq = max(max_freq, freq_hash[s[r]])

            if (r-l+1) - max_freq > k:
                freq_hash[s[l]] -= 1
                if freq_hash[s[l]] == 0:
                    del freq_hash[s[l]]
                l += 1
            
            max_len = max(max_len, r-l+1)
        return max_len