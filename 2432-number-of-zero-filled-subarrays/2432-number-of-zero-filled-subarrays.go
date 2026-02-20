func zeroFilledSubarray(nums []int) int64 {
    var cnt, curr int64 = 0, 0
    for _, num := range nums {
        if num == 0 {
            curr++
            cnt += curr
        } else {
            curr = 0
        }
    }
    return cnt
}