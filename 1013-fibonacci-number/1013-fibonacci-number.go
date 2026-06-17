func fib(n int) int {
    if n == 0 {
        return 0
    }

    memo := make([]int, n+1)

    return solve(n, memo)
}

func solve(n int, memo []int) int {
    if memo[n] != 0 {
        return memo[n]
    }

    if n <= 2 {
        return 1
    }

    memo[n] = solve(n -1, memo) + solve(n-2, memo)

    return memo[n]
}