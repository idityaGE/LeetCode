func minZeroArray(nums []int, queries [][]int) int {
    n := len(nums)
    
    canMakeZeroArray := func(k int) bool {
        diff := make([]int, n+1)
        for i := 0; i < k; i++ {
            left, right, val := queries[i][0], queries[i][1], queries[i][2]
            diff[left] += val
            diff[right+1] -= val
        }
        currVal := 0
        for i := 0; i < n; i++ {
            currVal += diff[i]
            if currVal < nums[i] {
                return false
            }
        }
        return true
    }
    
    allZero := true
    for _, x := range nums {
        if x != 0 {
            allZero = false
            break
        }
    }
    if allZero {
        return 0
    }
    
    left, right := 1, len(queries)
    if !canMakeZeroArray(right) {
        return -1
    }
    for left < right {
        mid := left + (right-left)/2
        if canMakeZeroArray(mid) {
            right = mid
        } else {
            left = mid + 1
        }
    }
    return left
}