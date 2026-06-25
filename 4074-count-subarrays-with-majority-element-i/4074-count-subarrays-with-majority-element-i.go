func countMajoritySubarrays(nums []int, target int) int {
    n := len(nums)
    var ans int64 = 0

    for l := 0; l < n; l++ {
        targetCount := 0 
        for r := l; r < n; r++ {
            if nums[r] == target {
                targetCount++
            }

            length := r - l + 1
            if targetCount > length/2 {
                ans++
            } 
        }
    }

    return int(ans)
}