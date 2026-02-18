func hasAlternatingBits(n int) bool {
    last := n & 1
    n >>= 1
    
    for n > 0 {
        temp := n & 1 
        if temp == last {
            return false
        }
        last = temp
        n >>= 1
    } 
    
    return true
}