class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        freq = {}
        goodPairs = 0
        
        for i, num in enumerate(nums):
            key = num - i
            goodPairs += freq.get(key, 0)
            freq[key] = freq.get(key, 0) + 1
        
        n = len(nums)
        return (n * (n - 1)) // 2 - goodPairs
        