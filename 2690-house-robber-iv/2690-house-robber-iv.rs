impl Solution {
    pub fn min_capability(nums: Vec<i32>, k: i32) -> i32 {
        fn can_steal_k_houses(nums: &Vec<i32>, k: i32, capability: i32) -> bool {
            let mut count = 0;
            let mut i = 0;
            while i < nums.len() {
                if nums[i] <= capability {
                    count += 1;
                    i += 2;
                } else {
                    i += 1;
                }
            }
            count >= k
        }

        let mut left = *nums.iter().min().unwrap();
        let mut right = *nums.iter().max().unwrap();

        while left < right {
            let mid = left + (right - left) / 2;
            if can_steal_k_houses(&nums, k, mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        left
    }
}