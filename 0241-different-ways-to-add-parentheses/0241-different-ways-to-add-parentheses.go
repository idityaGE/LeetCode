import "strconv"

func diffWaysToCompute(expression string) []int {
	return solve(expression)
}

func solve(exp string) []int {
	if len(exp) <= 2 {
		num, _ := strconv.Atoi(exp)
		return []int{num}
	}

    var res []int
	for i, ch := range exp {
		if ch == '+' || ch == '-' || ch == '*' {
			lh := solve(exp[:i])
			rh := solve(exp[i+1:])

			for _, j := range lh {
				for _, k := range rh {
					tmp := 0
					if ch == '*' {
						tmp = j * k
					} else if ch == '+' {
						tmp = j + k
					} else {
						tmp = j - k
					}
					res = append(res, tmp)
				}
			}
		}
	}

	return res
}