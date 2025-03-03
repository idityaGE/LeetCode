/**
 * @param {number[]} nums
 * @param {number} pivot
 * @return {number[]}
 */
var pivotArray = (nums, pivot) => [...nums.filter(n => n < pivot), ...nums.filter(n => n === pivot), ...nums.filter(n => n > pivot)]