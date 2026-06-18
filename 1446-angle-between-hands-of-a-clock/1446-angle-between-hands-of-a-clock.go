import "math"

func angleClock(hour int, minutes int) float64 {
    // 360 / 60 = 6 deg / min
    // 360 / 12 = 30 deg / hours 
    // 30 / 6 = 0.5 deg / per min

    mindeg := float64(minutes) * 6.0

    hourdeg := float64(hour%12)*30.0 + float64(minutes)*0.5

    diff := math.Abs(mindeg - hourdeg)

    if diff > 360-diff {
        return 360 - diff
    }

    return diff
}