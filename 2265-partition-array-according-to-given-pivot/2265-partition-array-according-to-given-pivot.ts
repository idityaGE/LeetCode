function pivotArray(nums: number[], pivot: number): number[] {
    return [...nums.filter(n => n < pivot), ...nums.filter(n => n === pivot), ...nums.filter(n => n > pivot)]
};