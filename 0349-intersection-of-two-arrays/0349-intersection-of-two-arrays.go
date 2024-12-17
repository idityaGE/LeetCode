func intersection(nums1 []int, nums2 []int) []int {
    res := []int{}
    mp := make(map[int]int)

    for _, num := range nums1 {
        mp[num] = mp[num] + 1
    }

    for _, num := range nums2 {
        if _, exists := mp[num]; exists {
            res = append(res, num)
            delete(mp, num)
        }
    }

    return res
}
