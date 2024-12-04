func singleNumber(nums []int) int {
    XOR := 0
    for i := 0; i < len(nums); i++ {
        XOR ^= nums[i]
    }
    return XOR
}