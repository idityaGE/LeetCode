func partitionLabels(s string) []int {
    lastOccurrence := make(map[rune]int)
    for i, char := range s {
        lastOccurrence[char] = i
    }

    result := []int{}
    start, end := 0, 0

    for i, char := range s {
        end = max(end, lastOccurrence[char])
        if i == end {
            result = append(result, end-start+1)
            start = i + 1
        }
    }

    return result
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}