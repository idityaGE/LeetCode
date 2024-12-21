function hammingWeight(n: number): number {
    let cnt = 0
    while (n != 0) {
        const bit = n & 1
        if (bit == 1) {
            cnt += 1
        }
        n >>= 1
    }
    return cnt
};