func numTilePossibilities(tiles string) int {
	charCnt := make([]int, 26)
	for _, ch := range tiles {
		charCnt[ch-'A']++
	}
	return findSeq(charCnt)
}

func findSeq(charCnt []int) int {
	cnt := 0
	for pos := 0; pos < 26; pos++ {
		if charCnt[pos] == 0 {
			continue
		}
		cnt++
		charCnt[pos]--
		cnt += findSeq(charCnt)
		charCnt[pos]++
	}
	return cnt
}