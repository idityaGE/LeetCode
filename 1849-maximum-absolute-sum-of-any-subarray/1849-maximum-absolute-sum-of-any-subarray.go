import (
  "math"
)

func maxAbsoluteSum(nums []int) int {
	maxSum, minSum := 0, 0
	currMaxSum, currMinSum := 0, 0
	for _, num := range nums {
		currMaxSum += num
		currMinSum += num
		maxSum = max(maxSum, currMaxSum)
		minSum = min(minSum, currMinSum)
    if currMaxSum < 0 { currMaxSum = 0 }
    if currMinSum > 0 { currMinSum = 0 }
	}
  return max(maxSum, int(math.Abs(float64(minSum))))
}