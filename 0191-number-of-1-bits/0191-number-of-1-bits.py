class Solution:
    def hammingWeight(self, n: int) -> int:
        cnt = 0
        while n != 0:
            bit = n & 1
            if bit == 1:
                cnt += 1
            n >>= 1
        return cnt
        