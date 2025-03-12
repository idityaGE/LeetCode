func maximumCount(nums []int) int {
    negCount := binarySearch(nums, 0)
    posCount := len(nums) - binarySearch(nums, 1)
    return max(negCount, posCount)
}

func binarySearch(nums []int, target int) int {
    left, right, result := 0, len(nums)-1, len(nums)
    
    for left <= right {
        mid := (left + right) / 2
        if nums[mid] < target {
            left = mid + 1
        } else {
            result = mid
            right = mid - 1
        }
    }
    
    return result
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}