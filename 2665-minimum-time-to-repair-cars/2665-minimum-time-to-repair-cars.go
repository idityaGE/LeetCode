func repairCars(ranks []int, cars int) int64 {
	left, right := int64(1), int64(ranks[0])*int64(cars)*int64(cars)

	canRepairAll := func(time int64) bool {
		totalCarsRepaired := int64(0)
		for _, rank := range ranks {
			totalCarsRepaired += int64(math.Sqrt(float64(time / int64(rank))))
			if totalCarsRepaired >= int64(cars) {
				return true
			}
		}
		return false
	}

	for left < right {
		mid := (left + right) / 2
		if canRepairAll(mid) {
			right = mid
		} else {
			left = mid + 1
		}
	}

	return left
}