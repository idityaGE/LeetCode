function tupleSameProduct(nums: number[]): number {
    const freq: Map<number, number> = new Map();
    let count = 0;

    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            const product = nums[i] * nums[j];
            freq.set(product, (freq.get(product) || 0) + 1);
        }
    }

    for (const n of freq.values()) {
        if (n > 1) {
            count += 8 * (n * (n - 1)) / 2;
        }
    }

    return count;
};