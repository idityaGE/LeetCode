impl Solution {
    pub fn longest_ones(nums: Vec<i32>, k: i32) -> i32 {
        let (mut l, mut zero) = (0, 0);

        for r in 0..nums.len() {
            if nums[r] == 0 {
                zero += 1;
            }

            if zero > k {
                if nums[l] == 0 {
                    zero -= 1;
                }
                l += 1;
            }
        }

        return (nums.len() - l) as i32
    }
}