class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        n, m = len(spells), len(potions)
        potions.sort()
        ans = [0]*n

        for i, spell in enumerate(spells):
            low, high = 0, m-1
            while low <= high:
                mid = (low + high) // 2
                if spell * potions[mid] >= success:
                    high = mid - 1
                else:
                    low = mid + 1
            ans[i] = m - low
        
        return ans