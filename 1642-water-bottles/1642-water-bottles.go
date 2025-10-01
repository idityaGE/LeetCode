func numWaterBottles(numBottles int, numExchange int) int {
	ans := numBottles
	curr := numBottles

	for curr >= numExchange {
        exc := curr / numExchange
        rem := curr - (exc * numExchange)
        curr = exc + rem
        ans += exc
    }

	return ans
}