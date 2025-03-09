func numberOfAlternatingGroups(colors []int, k int) int {
    l, r := 0, 0
    res := 0
    n := len(colors)
    for l < n {
        r++
        if colors[r % n] == colors[(r - 1) % n] {
            l = r
        } else if r - l + 1 == k {
            res++
            l++
        }
    }
    return res
}