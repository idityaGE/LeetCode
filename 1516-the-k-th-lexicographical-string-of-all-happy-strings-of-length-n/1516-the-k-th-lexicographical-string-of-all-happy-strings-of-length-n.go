import (
	"sort"
)

func getHappyString(n int, k int) string {
	var happyStr []string
	generateHappyStr(n, "", &happyStr)
	if len(happyStr) < k {
		return ""
	}
	sort.Strings(happyStr)
	return happyStr[k-1]
}

func generateHappyStr(n int, currentStr string, happyStr *[]string) {
	if len(currentStr) == n {
		*happyStr = append(*happyStr, currentStr)
		return
	}

	for ch := 'a'; ch <= 'c'; ch++ {
		if len(currentStr) > 0 && rune(currentStr[len(currentStr)-1]) == ch {
			continue
		}

		generateHappyStr(n, currentStr+string(ch), happyStr)
	}
}