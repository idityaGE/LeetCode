function maxAscendingSum(nums: number[]): number {
    const n = nums.length
    if(n == 0) return 0;
    if(n == 1) return nums[0];

    let maxSum = nums[0]
    let sum = nums[0]

    for(let i = 1; i < n; i++) {
        if(nums[i - 1] >= nums[i]) sum = 0;
        sum += nums[i]
        maxSum = Math.max(maxSum, sum) 
    }
    return maxSum
};