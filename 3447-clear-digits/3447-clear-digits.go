func isNum(ch rune) bool {
    return ch >= '0' && ch <= '9'
}

func clearDigits(s string) string {
    var stack []rune

    for _, ch := range s {
        if isNum(ch) {
            if len(stack) > 0 {
                stack = stack[:len(stack) - 1]
            }
        } else {
            stack = append(stack, ch)
        }
    }

    return string(stack)
}