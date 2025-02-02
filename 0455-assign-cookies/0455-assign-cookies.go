func findContentChildren(g []int, s []int) int {
    sort.Ints(g)
    sort.Ints(s)

    p, i := 0, 0

    for p < len(g) && i < len(s) {
        if g[p] <= s[i] {
            p++
        }
        i++
    }

    return p
}