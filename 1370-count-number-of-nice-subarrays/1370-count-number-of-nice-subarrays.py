class Solution:
    def fuck(self, nums: List[int], goal: int) -> int:
        if goal < 0:
            return 0

        cnt, sum, l = 0, 0, 0

        for r in range(len(nums)):
            sum += nums[r] % 2
            while sum > goal:
                sum -= nums[l] % 2
                l += 1
            cnt += r-l+1

        return cnt 

    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        cnt = self.fuck(nums, k) - self.fuck(nums, k-1)
        return cnt