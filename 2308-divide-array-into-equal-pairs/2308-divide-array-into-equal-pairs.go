func divideArray(nums []int) bool {
    freq := make(map[int]int)

    for _, num := range nums {
        freq[num]++
    }

    for _, val := range freq {
        if val%2 != 0 {
            return false
        }
    }

    return true
}