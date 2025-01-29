function numberOfSubarrays(nums: number[], k: number): number {
    const atmost = (goal: number): number => {
        if (goal < 0) return 0;
        let cnt = 0, sum = 0, l = 0;
        for(let r=0;r<nums.length;r++) {
            sum += nums[r] % 2
            while (sum > goal) 
                sum -= nums[l++] % 2
            cnt += r-l+1 
        }
        return cnt
    }

    return atmost(k) - atmost(k-1);
};