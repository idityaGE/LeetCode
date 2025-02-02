function check(nums: number[]): boolean {
    let cnt = 0;
    for(let i = 0; i < nums.length; i++) {
        if(nums[i] > nums[(i+1)%nums.length]) cnt++;
        if(cnt > 1) return false;
    }
    return true;
};