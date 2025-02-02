impl Solution {
    pub fn check(nums: Vec<i32>) -> bool {
        let mut cnt: i16 = 0;
        for i in 0..nums.len() {
            if nums[i] > nums[(i + 1) % nums.len()] {
                cnt += 1;
            }
            if cnt > 1 {
                return false;
            }
        }  
        return true;
    }
}