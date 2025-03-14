func maximumCandies(candies []int, k int64) int {
    left, right := 1, 10_000_000
    result := 0

    for left <= right {
        mid := left + (right-left)/2
        var childrenCount int64 = 0

        for _, candy := range candies {
            childrenCount += int64(candy / mid)
        }

        if childrenCount >= k {
            result = mid
            left = mid + 1
        } else {
            right = mid - 1
        }
    }

    return result
}