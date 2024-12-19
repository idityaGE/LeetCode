func plusOne(digits []int) []int {
	n := len(digits)
    carry := 1

	for i := n - 1; i >= 0 && carry > 0; i-- {
        digits[i] += carry
        if digits[i] == 10 {
            digits[i] = 0
            carry = 1
        } else {
            carry = 0
        }
	}

    if carry > 0 {
        digits = append([]int{1}, digits...)
    }

    return digits
}