func strStr(haystack string, needle string) int {
    if len(haystack) < len(needle){
        return -1
    }

    for i := range(len(haystack) - len(needle) + 1) {
        if haystack[i:i+len(needle)] == needle {
            return i
        }
    }

    return -1
        
}