class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        charCnt = [0] * 26
        for ch in tiles:
            charCnt[ord(ch) - ord('A')] += 1
        return self._findSeq(charCnt)

    def _findSeq(self, charCnt: list) -> int:
        cnt = 0
        for pos in range(26):
            if charCnt[pos] == 0:
                continue

            cnt += 1
            charCnt[pos] -= 1
            cnt += self._findSeq(charCnt)
            charCnt[pos] += 1
        
        return cnt
