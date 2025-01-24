from typing import List

class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        max_len, zero, l = 0, 0, 0

        for r in range(len(nums)):
            if nums[r] == 0:
                zero += 1
            
            while zero > k:
                if nums[l] == 0:
                    zero -= 1
                l += 1
            
            max_len = max(max_len, r - l + 1)

        return max_len
