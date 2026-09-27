func lengthOfLongestSubstring(s string) int {
    if len(s) == 0 {
        return 0
    }
    mpp := make(map[byte]int)
    left, right := 0,1
    mpp[s[left]]++ 

    ans := 1

    for right < len(s) && left < len(s) {
        mpp[s[right]]++
        if mpp[s[right]] > 1 {
            for left < right && mpp[s[right]] > 1 {
                mpp[s[left]]--
                left++
            }
        }

        if ans < (right - left + 1) {
            ans = right - left + 1
        }
        right++
    }

    return ans
}