impl Solution {
    pub fn number_of_subarrays(nums: Vec<i32>, k: i32) -> i32 {
        Self::atmost(&nums, k) - Self::atmost(&nums, k - 1)
    }
    pub fn atmost(nums: &Vec<i32>, goal: i32) -> i32 {
        if goal < 0 {
            return 0;
        }
        let (mut cnt, mut sum, mut l) = (0, 0, 0);

        for r in 0..nums.len() {
            sum += nums[r] % 2;
            while sum > goal {
                sum -= nums[l] % 2;
                l += 1;
            }
            cnt += r - l + 1;
        }
        cnt as i32
    }
}