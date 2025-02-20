func findDifferentBinaryString(nums []string) string {
	n := len(nums[0])
	freq := make(map[string]int)

	for _, s := range nums {
		freq[s]++
	}

    var allStr []string

    genBin(n, "", &allStr)

    for _, s := range allStr {
        freq[s]++
        if freq[s] == 1 {
            return s
        }
    }    
    return ""
}

func genBin(n int, currStr string, allStr *[]string) {
	if len(currStr) == n {
		*allStr = append(*allStr, currStr)
		return
	}

	for ch := '0'; ch <= '1'; ch++ {
		genBin(n, currStr+string(ch), allStr)
	}
}