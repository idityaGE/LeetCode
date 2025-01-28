function numSubarraysWithSum(nums: number[], goal: number): number {
    const atmost = (goal: number): number => {
        if (goal < 0) return 0;
        let cnt = 0, sum = 0, l = 0;
        for(let r=0;r<nums.length;r++) {
            sum += nums[r]
            while (sum > goal) 
                sum -= nums[l++]
            cnt += r-l+1 
        }
        return cnt
    }

    return atmost(goal) - atmost(goal-1);
};