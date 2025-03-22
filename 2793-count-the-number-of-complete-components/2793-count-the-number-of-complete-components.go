func countCompleteComponents(n int, edges [][]int) int {
    parent := make([]int, n)
    rank := make([]int, n)

    for i := 0; i < n; i++ {
        parent[i] = i
    }

    var find func(int) int
    find = func(x int) int {
        if parent[x] != x {
            parent[x] = find(parent[x])
        }
        return parent[x]
    }

    union := func(x, y int) {
        rootX, rootY := find(x), find(y)
        if rootX == rootY {
            return
        }
        if rank[rootX] < rank[rootY] {
            parent[rootX] = rootY
        } else if rank[rootX] > rank[rootY] {
            parent[rootY] = rootX
        } else {
            parent[rootY] = rootX
            rank[rootX]++
        }
    }

    for _, edge := range edges {
        union(edge[0], edge[1])
    }

    componentVertices := make(map[int]map[int]bool)
    componentEdges := make(map[int]int)

    for i := 0; i < n; i++ {
        root := find(i)
        if _, exists := componentVertices[root]; !exists {
            componentVertices[root] = make(map[int]bool)
            componentEdges[root] = 0
        }
        componentVertices[root][i] = true
    }

    for _, edge := range edges {
        root := find(edge[0])
        componentEdges[root]++
    }

    completeCount := 0
    for root, vertices := range componentVertices {
        numVertices := len(vertices)
        expectedEdges := numVertices * (numVertices - 1) / 2
        if componentEdges[root] == expectedEdges {
            completeCount++
        }
    }

    return completeCount
}