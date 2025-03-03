func pivotArray(nums []int, pivot int) []int {
    result := make([]int, len(nums))
    left, right := 0, len(nums) - 1

    for i, j := 0, len(nums) - 1; i < len(nums); i, j = i+1, j-1 {
        if nums[i] < pivot {
            result[left] = nums[i]
            left++
        }
        if nums[j] > pivot {
            result[right] = nums[j]
            right--
        }
    }

    for left <= right {
        result[left] = pivot
        left++
    }

    return result    
}