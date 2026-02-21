func evenNumberBitwiseORs(nums []int) int {
    res := 0
    for _, num := range nums {
        if num & 1 == 0 {
            res |= num
        }
    }

    return res
}