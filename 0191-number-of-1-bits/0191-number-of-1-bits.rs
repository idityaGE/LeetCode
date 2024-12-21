impl Solution {
    pub fn hamming_weight(mut n: i32) -> i32 {
        let mut cnt:i32 = 0;
        while n != 0 {
            let bit = n & 1;
            if bit == 1 {
                cnt += 1;
            }
            n >>= 1;
        }
        return cnt;
    }
}