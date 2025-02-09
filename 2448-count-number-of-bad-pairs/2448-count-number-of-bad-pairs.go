func countBadPairs(nums []int) int64 {
    freq := make(map[int]int)
    goodPairs := 0
    n := len(nums)

    for i, num := range nums {
        key := num - i
        if val, exists := freq[key]; exists {
            goodPairs += val
        }
        freq[key]++
    }

    // var badPairs int64 = 

    return int64(n*(n-1)/2 - goodPairs)
}
