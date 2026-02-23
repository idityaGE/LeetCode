import (
    "strconv"
)

func hasAllCodes(s string, k int) bool {
    n := len(s)
    if n < k {
        return false
    }

    total := 1 << k
    freq := make([]int, total)

    for i := 0; i <= n-k; i++ {
        sub := s[i : i+k]
        num, _ := strconv.ParseInt(sub, 2, 32)
        freq[num]++
    }

    for _, v := range freq {
        if v == 0 {
            return false
        }
    }

    return true
}