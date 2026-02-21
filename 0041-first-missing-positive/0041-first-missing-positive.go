func firstMissingPositive(nums []int) int {
    set := make(map[int]struct{})

    for _, num := range nums {
        set[num] = struct{}{}
    }

    for i := 1; i <= len(nums) + 1; i++ {
        if _, ok := set[i]; !ok {
            return i
        }
    }

    return -1
}