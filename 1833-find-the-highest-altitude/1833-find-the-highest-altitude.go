func largestAltitude(gain []int) int {
    maxx := 0
    alitude := 0
    for _, n := range gain {
        alitude += n
        if maxx < alitude {
            maxx = alitude
        }
    }
    return maxx
}