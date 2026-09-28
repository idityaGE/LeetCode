func searchRange(nums []int, target int) []int {
    l := lowerBound(nums, target)
    if l == len(nums) || nums[l] != target {
        return []int{-1, -1}
    }

    r := upperBound(nums, target) - 1
    return []int{l, r}
}

func lowerBound(nums []int, target int) int {
    left, right := 0, len(nums)

    for left < right {
        mid := left + (right-left)/2

        if nums[mid] < target {
            left = mid + 1
        } else {
            right = mid
        }
    }

    return left
}

func upperBound(nums []int, target int) int {
    left, right := 0, len(nums)

    for left < right {
        mid := left + (right-left)/2

        if nums[mid] <= target {
            left = mid + 1
        } else {
            right = mid
        }
    }

    return left
}
