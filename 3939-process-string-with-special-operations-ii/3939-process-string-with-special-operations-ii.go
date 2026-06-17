func processStr(s string, k int64) byte {
    var L int64 = 0

    for _, ch := range s {
        if ch == '*' {
            if L > 0 {
                L--
            }
        } else if ch == '#' {
            L *= 2
        } else if ch == '%' {
            continue
        } else {
            L++
        }
    } 

    if (k >= L) {
        return '.'
    }

    str := []rune(s)

    for i := len(str) - 1; i >= 0; i-- {
        if str[i] == '*' {
            L++
        } else if str[i] == '#' {
            L /= 2
            if k >= L {
                k -= L
            }
        } else if str[i] == '%' {
            k = L - k - 1
        } else {
            L--
        }

        if L == k {
            return byte(str[i])
        }
    }

    return byte('.')
}