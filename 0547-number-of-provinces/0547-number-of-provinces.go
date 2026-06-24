func findCircleNum(isConnected [][]int) int {
    n := len(isConnected)
    visited := make([]int, n)

    count := 0

    var dfs func(int)
    dfs = func(node int) {
        visited[node] = 1
        for idx, nei := range isConnected[node] {
            if nei == 1 && visited[idx] == 0 {
                dfs(idx)
            } 
        }
    }

    for i := range n {
        if visited[i] == 0 {
            dfs(i)
            count++
        }
    }

    return count
}