func minOperations(grid [][]int, x int) int {
    values := []int{}

    for _, row := range grid {
        for _, val := range row {
            values = append(values, val)
        }
    }   

    sort.Ints(values)

    for _, val := range values {
        if int(math.Abs(float64(val-values[0]))) % x != 0 {
            return -1
        }
    }

    median := values[len(values)/2]
    operations := 0

    for _, val := range values {
        operations += int(math.Abs(float64(val-median))) / x
    }

    return operations
}