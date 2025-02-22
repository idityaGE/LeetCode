func smallerNumbersThanCurrent(nums []int) []int {
    res := make([]int, len(nums))
    for i := 0; i < len(nums); i++ {
        c := 0
        for j := 0; j < len(nums); j++ {
            if j == i { continue }
            if nums[j] < nums[i] { c++ }
        }
        res[i] = c
    }
    return res
}