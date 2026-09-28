func maxDepth(s string) int {
    l := 0
    max := 0
    for _ , ch := range s {
        if ch == '(' {
            l++
        } else if ch == ')' {
            l--
        } 
        if l > max {
            max = l
        }
    }
    return max
}