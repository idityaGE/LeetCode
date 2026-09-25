func longestConsecutive(nums []int) int {
    if len(nums) == 0 {
        return 0
    }

    mpp := make(map[int]bool)
    for _, num := range nums {
        mpp[num] = true
    }

    longest := 0

    for num := range mpp {
        if !mpp[num - 1] {
            curr := 1
            
            for mpp[num+curr] {
                curr++
            }

            if curr > longest {
                longest = curr
            }
        }
    }

    return longest
}