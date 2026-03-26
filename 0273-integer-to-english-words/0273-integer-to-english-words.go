import "strings"

func numberToWords(num int) string {
	if num == 0 {
		return "Zero"
	}
	return strings.TrimSpace(solve(num))
}

var mp = map[int]string{
	1:  "One",
	2:  "Two",
	3:  "Three",
	4:  "Four",
	5:  "Five",
	6:  "Six",
	7:  "Seven",
	8:  "Eight",
	9:  "Nine",
	10: "Ten",
	11: "Eleven",
	12: "Twelve",
	13: "Thirteen",
	14: "Fourteen",
	15: "Fifteen",
	16: "Sixteen",
	17: "Seventeen",
	18: "Eighteen",
	19: "Nineteen",

	20: "Twenty",
	30: "Thirty",
	40: "Forty",
	50: "Fifty",
	60: "Sixty",
	70: "Seventy",
	80: "Eighty",
	90: "Ninety",
}

func solve(n int) string {
	if n == 0 {
		return ""
	}
	if n < 10 {
		return mp[n]
	}

	if n >= 10 && n <= 19 {
		return mp[n]
	}

	if n >= 20 && n < 100 {
		rest := n % 10
		st := mp[n-rest]
		if rest != 0 {
			st += " " + mp[rest]
		}
		return st
	}

	if n > 99 && n < 1000 {
		if n%100 == 0 {
			return mp[n/100] + " Hundred"
		}
		return mp[n/100] + " Hundred " + solve(n%100)
	}

	if n > 999 && n < 1_000_000 {
		if n%1_000 == 0 {
			return solve(n/1_000) + " Thousand"
		}
		return solve(n/1_000) + " Thousand " + solve(n%1_000)
	}

	if n > 999_999 && n < 1_000_000_000 {
		if n%1_000_000 == 0 {
			return solve(n/1_000_000) + " Million"
		}
		return solve(n/1_000_000) + " Million " + solve(n%1_000_000)
	}

		if n%1_000_000_000 == 0 {
			return solve(n/1_000_000_000) + " Billion"
		}
		return solve(n/1_000_000_000) + " Billion " + solve(n%1_000_000_000)
}

