class Solution:
    def countValidSelections(self, nums: List[int]) -> int:
        def isValid(nums, curr, dir): # 1 -> Right, 0 -> Left
            arr = nums.copy()
            while 0 <= curr < len(arr):
                if arr[curr] > 0:
                    arr[curr] -= 1
                    dir = False if dir else True
                curr += -1 if dir else 1
            
            return all(x == 0 for x in arr)
        
        valid = 0

        for idx, num in enumerate(nums):
            if num == 0:
                if isValid(nums, idx, True):
                    valid += 1
                if isValid(nums, idx, False):
                    valid += 1
        
        return valid
