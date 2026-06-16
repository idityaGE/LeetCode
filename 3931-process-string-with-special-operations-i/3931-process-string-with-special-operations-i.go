func processStr(s string) string {
    var res []rune

    for _, ch := range s {
        if ch == '*' {
            if len(res) > 0 {
                res = res[:len(res)-1]
            }
        } else if ch == '#' {
            res = append(res, res...)
        } else if ch == '%' {
            for i, j := 0, len(res)-1; i < j; i, j = i+1, j-1 {
                res[i], res[j] = res[j], res[i]
            }
        } else {
            res = append(res, ch)
        }
    }

    return string(res)
}