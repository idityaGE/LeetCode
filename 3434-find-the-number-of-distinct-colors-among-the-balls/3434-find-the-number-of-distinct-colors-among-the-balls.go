func queryResults(limit int, queries [][]int) []int {
    keyToValue := make(map[int]int)
    countValue := make(map[int]int)
    result := make([]int, 0, len(queries))
    cnt := 0

    for _, q := range queries {
        key, val := q[0], q[1]

        if oldvalue, exists := keyToValue[key]; exists {
            countValue[oldvalue]--
            if countValue[oldvalue] == 0 {
                cnt--
            }
        }
        
        keyToValue[key] = val
        if countValue[val] == 0 {
            cnt++
        }
        countValue[val]++
        result = append(result, cnt)
    }

    return result
}