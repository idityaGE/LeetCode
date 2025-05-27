impl Solution {
    pub fn difference_of_sums(n: i32, m: i32) -> i32 {
        let (mut num1,mut num2) = (0, 0);
        for i in 1..n+1 {
            if i % m == 0 {
                num2 += i;
            } else {
                num1 += i; 
            }
        }
        num1-num2
    }
}