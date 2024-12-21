func hammingWeight(n int) int {
    cnt := 0
    for n != 0 {
        bit := n & 1
        if bit == 1 {
            cnt += 1
        }
        n >>= 1
    }
    return cnt
}