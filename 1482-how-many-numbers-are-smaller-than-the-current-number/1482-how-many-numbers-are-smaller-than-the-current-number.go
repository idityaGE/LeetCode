func smallerNumbersThanCurrent(nums []int) []int {
    arr := make([]int, 101)
    res := make([]int, len(nums))
    for _, v := range nums {
        arr[v]++
    }
    for i := 1; i < 101; i++ {
        arr[i] = arr[i] + arr[i - 1]
    }
    for i := 0; i < len(nums); i++ {
        if nums[i] == 0 {
            res[i] = 0
        } else {
            res[i] = arr[nums[i] - 1]
        }
    }
    return res
}