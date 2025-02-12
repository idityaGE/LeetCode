func digitSum(num int) int {
    sum := 0
    for num != 0 {
        sum += num % 10
        num /= 10
    }
    return sum
}

func maximumSum(nums []int) int {
    mp := make(map[int]int)
    maxSum := -1

    for _, num := range nums {
        digiSum := digitSum(num)
        if oldVal, exists := mp[digiSum]; exists {
            maxSum = max(maxSum, num + oldVal);
            if oldVal < num {
                mp[digiSum] = num
            }
        } else {
            mp[digiSum] = num
        }
    }

    return maxSum
}