class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        def backTrack(i: int) -> bool:
            if sz == i:
                return True
            if ans[i] != 0:
                return backTrack(i + 1)

            for num in range(n, 0, -1):
                if used[num]:
                    continue
                if num == 1:
                    ans[i] = 1
                    used[1] = True
                    if backTrack(i + 1):
                        return True
                    ans[i] = 0
                    used[1] = False
                    continue
                if i + num >= sz or ans[i + num] != 0:
                    continue
                ans[i] = num
                ans[i + num] = num
                used[num] = True

                if backTrack(i + 1):
                    return True
                ans[i] = 0
                ans[i + num] = 0
                used[num] = False
            return False

        sz = 2 * n - 1
        ans = [0] * sz
        used = [False] * (n + 1)
        backTrack(0)

        return ans
