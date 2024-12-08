func singleNumber(nums []int) []int {
    XOR := 0
    for _, num := range nums {
        XOR ^= num
    }
    rightmostSetBit := XOR & ^(XOR - 1)
    b1, b2 := 0, 0
    for _, num := range nums {
        if (num & rightmostSetBit) != 0 {
            b1 ^= num
        } else {
            b2 ^= num
        }
    }
    if b2 > b1 {
        return []int{b1,b2}
    }
    return []int{b2, b1}
}