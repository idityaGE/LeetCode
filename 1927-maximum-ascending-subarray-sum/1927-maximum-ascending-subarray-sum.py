class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        n = len(nums)

        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        
        sum = maxSum = nums[0]
        
        for i in range(1, len(nums)):
            if nums[i - 1] >= nums[i]:
                sum = 0
            sum += nums[i]
            maxSum = max(maxSum, sum)
        
        return maxSum