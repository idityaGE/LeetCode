func totalFruit(fruits []int) int {
    if len(fruits) == 0 {
        return 0
    }

    fruitCount := make(map[int]int)
    maxFruits := 0
    left := 0

    for right := 0; right < len(fruits); right++ {
        fruitCount[fruits[right]]++

        for len(fruitCount) > 2 {
            fruitCount[fruits[left]]--
            
            if fruitCount[fruits[left]] == 0 {
                delete(fruitCount, fruits[left])
            }
            
            left++
        }

        currentWindowSize := right - left + 1
        if currentWindowSize > maxFruits {
            maxFruits = currentWindowSize
        }
    }

    return maxFruits
}