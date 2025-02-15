func partition(x, target int) bool {
    if target == x {
        return true
    }
    if x == 0 {
        return target == 0
    }

    for m := 10; m <= 1000; m *= 10 {
		if partition(x/m, target-x%m) {
			return true
		}
	}

    return false
}

func punishmentNumber(n int) int {
    sum := 0

    for i := 1; i <= n; i++ {
        x := i * i 
        if partition(x, i) {
            sum += x
        }
    }

    return sum
}