use std::collections::HashMap;
impl Solution {
    pub fn count_bad_pairs(nums: Vec<i32>) -> i64 {
        let mut freq: HashMap<i32, i64> = HashMap::new();
        let mut good_pairs: i64 = 0;
        let n = nums.len() as i64;

        for (i, &num) in nums.iter().enumerate() {
            let key = num - i as i32;
            if let Some(&count) = freq.get(&key) {
                good_pairs += count;
            }
            *freq.entry(key).or_insert(0) += 1;
        }

        let total_pairs = n * (n - 1) / 2;
        let bad_pairs = total_pairs - good_pairs;

        bad_pairs
    }
}