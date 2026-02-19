func countBinarySubstrings(s string) int {
    res, prev, strk := 0, 0, 1

    for i := 1; i < len(s); i++ {
        if s[i] == s[i - 1] {
            strk++
        } else {
            prev = strk
            strk = 1
        }
        if strk <= prev {
            res++
        }
    }

    return res
}