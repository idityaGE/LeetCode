func sumAndMultiply(n int) int64 {
    var xtem int64 = 0
    sum := 0

    for n > 0 {
        last := n % 10
        if last != 0 {
            sum += last
            xtem = xtem * 10 + int64(last)
        }
        n /= 10
    }

    var x int64 = 0
    for xtem > 0 {
        last := xtem % 10
        x = x * 10 + last
        xtem /= 10
    }


    return x * int64(sum)
}