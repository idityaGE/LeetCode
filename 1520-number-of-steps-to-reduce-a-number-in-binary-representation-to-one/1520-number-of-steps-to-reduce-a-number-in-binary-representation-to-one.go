func numSteps(s string) int {
    oper, carry := 0, 0
    
    // Process from right to left (skip the leftmost bit)
    for i := len(s) - 1; i > 0; i-- {
        bit := int(s[i] - '0')
        
        if (bit + carry) % 2 == 1 {
            // Odd: need to add 1, then divide by 2
            oper += 2
            carry = 1
        } else {
            // Even: just divide by 2
            oper++
        }
    }
    
    return oper + carry
}