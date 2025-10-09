class Solution:
    def minTime(self, skill: List[int], mana: List[int]) -> int:
        n, m = len(skill), len(mana)
        times = [0] * n

        for j in range(m):
            curr_time = 0
            for i in range(n):
                curr_time = max(curr_time, times[i]) + skill[i] * mana[j]
            times[n - 1] = curr_time
            for i in range(n-2, -1, -1):
                times[i] = times[i + 1] - skill[i + 1] * mana[j]
        return times[n - 1]
        