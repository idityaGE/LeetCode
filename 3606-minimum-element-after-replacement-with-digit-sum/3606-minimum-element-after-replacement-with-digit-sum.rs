impl Solution {
    fn digit_sum(mut num: i32) -> i32 {
        let mut sum = 0;
        while num > 0 {
            sum += num  % 10;
            num /= 10;
        }
        sum
    } 

    pub fn min_element(nums: Vec<i32>) -> i32 {
        let mut min = 1 << 9;
        for num in nums {
            let sum = Self::digit_sum(num);
            if sum < min {
                min = sum;
            }
        }
        min
    }
}