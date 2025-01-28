impl Solution {
    pub fn num_subarrays_with_sum(nums: Vec<i32>, goal: i32) -> i32 {
        Self::atmost(&nums, goal) - Self::atmost(&nums, goal - 1)
    }

    pub fn atmost(nums: &Vec<i32>, goal: i32) -> i32 {
        if goal < 0 {
            return 0;
        }
        let (mut cnt, mut sum, mut l) = (0, 0, 0);

        for r in 0..nums.len() {
            sum += nums[r];
            while sum > goal {
                sum -= nums[l];
                l += 1;
            }
            cnt += r - l + 1;
        }
        cnt as i32
    }
}
