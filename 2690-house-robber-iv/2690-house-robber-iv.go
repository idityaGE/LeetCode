import (
	"math"
)

func minCapability(nums []int, k int) int {
    right, left := maxAndMin(nums)

    for left < right {
        mid := left + (right-left)/2
        if canStealKHouses(nums, k, mid) {
            right = mid
        } else {
            left = mid + 1
        }
    }
    return left
}

func canStealKHouses(nums []int, k, mid int) bool {
    cnt, i := 0, 0
    for i < len(nums) {
        if nums[i] <= mid {
            cnt++
            i += 2
        } else {
            i++
        }
    }
    return cnt >= k
}

func maxAndMin(nums []int) (int, int) {
    maxEle := math.MinInt32
    minEle := math.MaxInt32

    for _, num := range nums {
        if num < minEle {
            minEle = num
        }
        if num > maxEle {
            maxEle = num
        }
    }

    return maxEle, minEle
}
