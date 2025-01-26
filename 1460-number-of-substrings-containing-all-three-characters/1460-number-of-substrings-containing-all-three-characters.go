func numberOfSubstrings(s string) int {
	lastseen := []int{-1, -1, -1}
	cnt := 0

	for i := 0; i < len(s); i++ {
		lastseen[s[i]-'a'] = i

		if lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1 {
			cnt += 1 + int(math.Min(float64(lastseen[0]),
                                    math.Min(float64(lastseen[1]), 
                                    float64(lastseen[2]))))
		}
	}

	return cnt
}