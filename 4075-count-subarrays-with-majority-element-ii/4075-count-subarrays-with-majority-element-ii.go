func countMajoritySubarrays(nums []int, target int) int64 {
	n := len(nums)
	pref := n

	freq := make([]int, 2*n+1)
	freq[n] = 1

	var less int64
	var ans int64

	for _, num := range nums {
		if num == target {
			less += int64(freq[pref])
			pref++
		} else {
			pref--
			less -= int64(freq[pref])
		}

		freq[pref]++
		ans += less
	}

	return ans
}