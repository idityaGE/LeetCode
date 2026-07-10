func pathExistenceQueries(n int, nums []int, maxDiff int, queries [][]int) []int {
    order := make([]int, n)

    for i := 0; i < n; i++ {
        order[i] = i
    }

    sort.Slice(order, func(i, j int) bool {
        return nums[order[i]] < nums[order[j]]
    })

    pos := make([]int, n)

    values := make([]int, n)

    for i := 0; i < n; i++ {
        values[i] = nums[order[i]]
        pos[order[i]] = i
    }

    LOG := 1

    for (1 << LOG) <= n {
        LOG++
    }

    jump := make([][]int, LOG)

    for p := 0; p < LOG; p++ {
        jump[p] = make([]int, n)
    }

    r := 0

    for i := 0; i < n; i++ {
        if r < i {
            r = i
        }

        for r+1 < n && values[r+1]-values[i] <= maxDiff {
            r++
        }

        jump[0][i] = r
    }

    for p := 1; p < LOG; p++ {
        for i := 0; i < n; i++ {
            jump[p][i] = jump[p-1][jump[p-1][i]]
        }
    }

    answer := make([]int, len(queries))

    for q, query := range queries {
        left := pos[query[0]]
        right := pos[query[1]]

        if left > right {
            left, right = right, left
        }

        if left == right {
            answer[q] = 0
            continue
        }

        current := left
        distance := 0

        for p := LOG - 1; p >= 0; p-- {
            if jump[p][current] < right {
                current = jump[p][current]
                distance += 1 << p
            }
        }

        if jump[0][current] >= right {
            answer[q] = distance + 1
        } else {
            answer[q] = -1
        }
    }

    return answer
}