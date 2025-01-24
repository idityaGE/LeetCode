from typing import List

class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        l = zero = 0

        for r in range(len(nums)):
            zero += nums[r] == 0
            if zero > k:
                zero -= nums[l] == 0
                l += 1
        
        return len(nums) - l
