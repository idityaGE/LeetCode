class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        k = 0
        inc = 1
        prevInc = 0
        for i in range(1, len(nums)):
            if nums[i - 1] < nums[i]:
                inc += 1
            else:
                prevInc = inc
                inc = 1
            k = max(k, max(inc >> 1, min(prevInc, inc)))
        return k
