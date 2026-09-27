	func isPalindrome(s string) bool {
		left, right := 0, len(s)-1

		for left < right {
			for left < right && !isAlphaNum(s[left]) {
				left++
			}
			for left < right && !isAlphaNum(s[right]) {
				right--
			}

			if toLower(s[left]) != toLower(s[right]) {
				return false
			}

			left++
			right--
		}

		return true
	}

	func isAlphaNum(c byte) bool {
		return c >= 'a' && c <= 'z' ||
			c >= 'A' && c <= 'Z' ||
			c >= '0' && c <= '9'
	}

	func toLower(c byte) byte {
		if c >= 'A' && c <= 'Z' {
			return c + 32
		}
		return c
	}