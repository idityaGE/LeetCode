func maximumTripletValue(nums []int) int64 {
	n := len(nums)
    var res int64 = 0
    for k := 2; k < n; k++ {
        maxPrefix := nums[0]
        for j := 1; j < k; j++ {
            res = max(res, int64(maxPrefix-nums[j])*int64(nums[k]))
            maxPrefix = max(maxPrefix, nums[j])
        }
    }
    return res
}