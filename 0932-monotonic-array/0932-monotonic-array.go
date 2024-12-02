func isMonotonic(nums []int) bool {
    n := len(nums)

    inc, dec := 0, 0

    for i := 0; i < n-1; i++ {
        if nums[i] <= nums[i+1] {
            inc += 1
        }
        if nums[i] >= nums[i+1] {
            dec += 1
        }
    }

    if (inc == n-1) || (dec == n-1) {
        return true
    }

    return false
}