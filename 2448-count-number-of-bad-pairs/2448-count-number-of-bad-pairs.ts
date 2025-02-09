function countBadPairs(nums: number[]): number {
    let freq: Map<number, number> = new Map()
    let goodPairs = 0
    let n = nums.length

    for (let i = 0; i < n; i++) {
        const key = nums[i] - i
        goodPairs += freq.get(key) || 0
        freq.set(key, (freq.get(key) || 0) + 1)
    }

    const totalPairs = (n * (n - 1)) / 2
    const badPairs = totalPairs - goodPairs

    return badPairs;
};