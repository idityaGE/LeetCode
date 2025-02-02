func check(nums []int) bool {
    cnt := 0

    for i := 0; i < len(nums); i++ {
        if nums[i] > nums[(i+1) % len(nums)] {
            cnt += 1
        }
        if cnt > 1 {
            return false
        }
    }  
    return true
}