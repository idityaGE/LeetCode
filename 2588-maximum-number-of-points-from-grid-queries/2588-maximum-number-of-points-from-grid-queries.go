func maxPoints(grid [][]int, queries []int) []int {
	rows, cols := len(grid), len(grid[0])
	directions := [][]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}

	sortedQueries := make([][]int, len(queries))
	for i, val := range queries {
		sortedQueries[i] = []int{val, i}
	}
	sort.Slice(sortedQueries, func(i, j int) bool {
		return sortedQueries[i][0] < sortedQueries[j][0]
	})

	result := make([]int, len(queries))

	h := &MinHeap{}
	heap.Init(h)
	visited := make([][]bool, rows)
	for i := range visited {
		visited[i] = make([]bool, cols)
	}

	heap.Push(h, []int{grid[0][0], 0, 0})
	visited[0][0] = true
	points := 0

	for _, q := range sortedQueries {
		queryVal, queryIdx := q[0], q[1]

		for h.Len() > 0 && (*h)[0][0] < queryVal {
			cur := heap.Pop(h).([]int)
			_, r, c := cur[0], cur[1], cur[2]
			points++

			for _, d := range directions {
				nr, nc := r+d[0], c+d[1]
				if nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc] {
					heap.Push(h, []int{grid[nr][nc], nr, nc})
					visited[nr][nc] = true
				}
			}
		}

		result[queryIdx] = points
	}

	return result
}

type MinHeap [][]int

func (h MinHeap) Len() int           { return len(h) }
func (h MinHeap) Less(i, j int) bool { return h[i][0] < h[j][0] }
func (h MinHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *MinHeap) Push(x interface{}) {
	*h = append(*h, x.([]int))
}

func (h *MinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[:n-1]
	return x
}