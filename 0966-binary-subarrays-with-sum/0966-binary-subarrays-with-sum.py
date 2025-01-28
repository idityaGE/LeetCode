class Solution:
    def fuck(self, nums: List[int], goal: int) -> int:
        if goal < 0:
            return 0

        cnt, sum, l = 0, 0, 0

        for r in range(len(nums)):
            sum += nums[r]
            while sum > goal:
                sum -= nums[l]
                l += 1
            cnt += r-l+1

        return cnt 
    
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        cnt = self.fuck(nums, goal) - self.fuck(nums, goal-1)
        return cnt