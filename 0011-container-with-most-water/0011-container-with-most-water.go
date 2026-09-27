func maxArea(height []int) int {
    maxArea := 0

    left, right := 0, len(height) - 1
    
    for left < right {
        w := right - left
        h := min(height[left], height[right])

        if (w * h) > maxArea {
            maxArea = w*h
        } 

        if height[left] <= height[right] {
            left++
        } else {
            right--
        }
    }

    return maxArea
}

func min(a, b int) int {
    if a <= b {
        return a 
    }
    return b 
}
