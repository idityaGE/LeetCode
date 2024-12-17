use std::collections::HashMap;

impl Solution {
    pub fn intersection(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut res = Vec::new();
        let mut mp = HashMap::new();

        for &num in &nums1 {
            *mp.entry(num).or_insert(0) += 1;
        }

        for &num in &nums2 {
            if mp.contains_key(&num) {
                res.push(num);
                mp.remove(&num);
            }
        }

        res
    }
}