impl Solution {
    pub fn count_negatives(grid: Vec<Vec<i32>>) -> i32 {
        let mut cnt = 0;

        for arr in grid {
            for n in arr.into_iter().rev() {
                if n >= 0 {
                    break;
                }
                cnt += 1;
            }
        }

        cnt
    }
}