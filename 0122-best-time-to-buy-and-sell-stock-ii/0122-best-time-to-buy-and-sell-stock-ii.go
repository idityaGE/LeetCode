func maxProfit(prices []int) int {
    maxProfit := 0

    for i := 1; i < len(prices); i++ {
        if val := prices[i] - prices[i - 1]; val > 0 {
            maxProfit += val
        }
    }

    return maxProfit
}