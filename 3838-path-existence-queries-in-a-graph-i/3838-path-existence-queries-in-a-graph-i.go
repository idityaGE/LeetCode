func pathExistenceQueries(n int, nums []int, maxDiff int, queries [][]int) []bool {
    comp := make([]int, n)
    id := 0

    for i := 1; i < n; i++ {
        if nums[i]-nums[i-1] > maxDiff {
            id++
        }
        comp[i] = id
    }

    ans := make([]bool, len(queries))
    for i, q := range queries {
        ans[i] = comp[q[0]] == comp[q[1]]
    }

    return ans
}