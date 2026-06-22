func maxNumberOfBalloons(text string) int {
    str := []rune(text)
    freq := make(map[rune]int)
    for _, ch := range str {
        if ch == 'b' || ch == 'a' || ch == 'l' || ch == 'o' || ch == 'n' {
            freq[ch]++
        }
    }

    if len(freq) < 5 {
        return 0
    }

    count := (1 << 31)

    for key, val := range freq {
        if key == 'b' || key == 'a' || key == 'n' {
            if count > val {
                count = val
            } 
        } else if key == 'l' || key == 'o' {
            if count > (val/2) {
                count = val / 2
            }
        }
    }

    return count
}