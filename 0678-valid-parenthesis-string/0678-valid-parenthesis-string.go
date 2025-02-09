func checkValidString(s string) bool {
    low := 0
    high := 0

    for _, c := range s {
        if c == '(' {
            low++ 
            high++
        } else if c == ')' {
            low-- 
            high--
        } else {
            low-- 
            high++
        }

        if (high < 0) {
            return false // Too many ')'
        }
        if (low < 0) {
            low = 0 // '*' can be empty, so reset low
        }
    }

    return low == 0;
}