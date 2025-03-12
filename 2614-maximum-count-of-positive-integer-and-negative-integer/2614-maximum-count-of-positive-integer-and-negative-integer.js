var maximumCount = function(nums) {
    let negCount = binarySearch(nums, 0);
    let posCount = nums.length - binarySearch(nums, 1);
    return Math.max(negCount, posCount);
};

var binarySearch = function(nums, target) {
    let left = 0, right = nums.length - 1, result = nums.length;
    
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            result = mid;
            right = mid - 1;
        }
    }
    
    return result;
};