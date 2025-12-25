class Solution:
    def maximumHappinessSum(self, hp: List[int], k: int) -> int:
        hp.sort(reverse=True)

        sum = 0
        for i in range(k):
            curr = hp[i] - i
            if curr > 0:
                sum += curr
            else:
                break

        return sum
            
             
        