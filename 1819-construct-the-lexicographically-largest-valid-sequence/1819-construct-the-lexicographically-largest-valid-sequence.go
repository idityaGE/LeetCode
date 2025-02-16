func constructDistancedSequence(n int) []int {
    size := 2*n - 1
    sequence := make([]int, size)
    used := make([]bool, n+1)

    // Define the backtracking function.
    // This function tries to place numbers in the sequence starting from the given index.
    var backtrack func(index int) bool
    backtrack = func(index int) bool {
        // If we've reached the end of the sequence, return true.
        // This means we've successfully constructed a valid sequence.
        if index == size {
            return true
        }

        // If the current index is already filled, move to the next index.
        if sequence[index] != 0 {
            return backtrack(index + 1)
        }

        // Try placing numbers from n down to 1.
        // This ensures the sequence is lexicographically largest.
        for i := n; i >= 1; i-- {
            // If the number i has already been used, skip it.
            if used[i] {
                continue
            }

            // Handle the case for the number 1.
            // The number 1 appears only once in the sequence.
            if i == 1 {
                // Place 1 at the current index.
                sequence[index] = i
                used[i] = true

                // Recursively try to fill the rest of the sequence.
                if backtrack(index + 1) {
                    return true
                }

                // If placing 1 here doesn't lead to a valid sequence, backtrack.
                sequence[index] = 0
                used[i] = false
                continue
            }

            // For numbers greater than 1, ensure the second occurrence is at the correct distance.
            // The second occurrence of i must be at index + i.
            if index+i >= size || sequence[index+i] != 0 {
                // If the position is out of bounds or already occupied, skip this number.
                continue
            }

            // Place the number i at the current index and at index + i.
            sequence[index] = i
            sequence[index+i] = i
            used[i] = true

            // Recursively try to fill the rest of the sequence.
            if backtrack(index + 1) {
                return true
            }

            // If placing i here doesn't lead to a valid sequence, backtrack.
            sequence[index] = 0
            sequence[index+i] = 0
            used[i] = false
        }
        
        return false
    }

    backtrack(0)
    return sequence
}