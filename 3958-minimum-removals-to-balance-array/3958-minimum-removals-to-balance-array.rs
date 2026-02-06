impl Solution {
    pub fn min_removal(mut nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len() as usize;
        nums.sort_unstable();

        let (mut i, mut max_len) = (0, 0);

        let k_long =  k as i64;

        for j in 0..n {
            while (nums[j] as i64) > (nums[i] as i64) * k_long {
                i += 1;
            }

            max_len = max_len.max(j - i + 1);
        }

        (n as i32) - (max_len as i32)
    }
}