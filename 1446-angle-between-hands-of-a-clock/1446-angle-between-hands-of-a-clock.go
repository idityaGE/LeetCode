import "math"

func angleClock(hour int, minutes int) float64 {
    mindeg := float64(minutes) * 6.0

    hourdeg := float64(hour%12)*30.0 + float64(minutes)*0.5

    diff := math.Abs(mindeg - hourdeg)

    if diff > 360-diff {
        return 360 - diff
    }

    return diff
}