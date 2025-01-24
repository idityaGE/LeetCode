function longestOnes(nums: number[], k: number): number {
    let maxLen = 0, zero = 0, l = 0;

    for (let r = 0; r < nums.length; r++) {
        if (nums[r] === 0) zero++;
        while (zero > k) if (nums[l++] === 0) zero--;
        maxLen = Math.max(maxLen, r - l + 1);
    }
    
    return maxLen;
}
