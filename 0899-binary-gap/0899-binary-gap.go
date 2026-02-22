func binaryGap(n int) int {
	maxDis := 0

	st := -1
	for n > 0 {
		temp := n & 1

		if temp == 1 {
			if st == -1 {
				st = 0
			} else {
				if st >= maxDis {
					maxDis = st + 1
				}
				st = 0
			}
		}
		if temp == 0 && st != -1 {
			st++
		}
		n >>= 1
	}

	return maxDis
}