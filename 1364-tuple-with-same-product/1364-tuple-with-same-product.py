from typing import List
from collections import defaultdict

class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        freq = defaultdict(int)
        cnt = 0

        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                product = nums[i] * nums[j]
                freq[product] += 1

        for n in freq.values():
            if n > 1:
                cnt += 8 * (n * (n - 1) // 2)

        return cnt
