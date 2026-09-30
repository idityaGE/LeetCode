func minEatingSpeed(piles []int, h int) int {
    max := piles[0]

    for _, pile := range piles {
        if pile > max {
            max = pile
        }
    }

    low, high := 1, max

    for low < high {
        mid := low + (high-low)/2

        if canEat(piles, h, mid) {
            high = mid
        } else {
            low = mid + 1
        }
    }

    return low
}

func canEat(piles []int, h, speed int) bool {
    hours := 0

    for _, pile := range piles {
        hours += (pile + speed - 1) / speed

        if hours > h {
            return false
        }
    }

    return true
}