use std::collections::HashMap;
impl Solution {
    pub fn tuple_same_product(nums: Vec<i32>) -> i32 {
        let mut freq = HashMap::new();
        let n = nums.len();
        let mut cnt = 0;

        for i in 0..n {
            for j in i+1..n {
                let prod = nums[i] * nums[j];
                *freq.entry(prod).or_insert(0) += 1;
            }
        }

        for &n in freq.values() {
            if n > 1 {
                cnt += 8 * (n * (n - 1) / 2);
            }
        }

        cnt as i32
    }
}