class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        p = i = 0
        while p < len(g) and i < len(s):
            if g[p] <= s[i]: 
                p += 1
            i += 1
        return p
