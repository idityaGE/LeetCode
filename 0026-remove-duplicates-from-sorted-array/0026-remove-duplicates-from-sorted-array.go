func removeDuplicates(nums []int) int {
    k := 0

    for i := 0; i < len(nums); i++ {
        j := i + 1
        for j < len(nums) && nums[i] == nums[j] {
            j++
        }

        nums[k] = nums[i]
        k++

        i = j - 1
    }

    return k
}