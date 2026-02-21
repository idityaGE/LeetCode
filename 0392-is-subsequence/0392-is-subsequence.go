func isSubsequence(s string, t string) bool {
    if len(s) == 0 {
        return true
    }

	i := 0

	for _, ch := range t {
		if byte(ch) == s[i] {
			i++
		}
		if i == len(s) {
			return true
		}
	}

	return false
}