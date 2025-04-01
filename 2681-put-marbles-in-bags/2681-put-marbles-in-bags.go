func putMarbles(weights []int, k int) int64 {
    if k == 1 {
        return 0
    }

    pairSums := make([]int, len(weights)-1)
    for i := 0; i < len(weights)-1; i++ {
        pairSums[i] = weights[i] + weights[i+1]
    }

    sort.Ints(pairSums)

    var minScore, maxScore int64
    for i := 0; i < k-1; i++ {
        minScore += int64(pairSums[i])
        maxScore += int64(pairSums[len(pairSums)-1-i])
    }

    return maxScore - minScore
}