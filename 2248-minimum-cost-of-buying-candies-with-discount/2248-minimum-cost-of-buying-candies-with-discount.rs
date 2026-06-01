impl Solution {
    pub fn minimum_cost(mut cost: Vec<i32>) -> i32 {
        cost.sort_unstable();

        let mut total = 0;

        for i in (0..cost.len()).rev().step_by(3) {
            total += cost[i];
            
            if i > 0 {
                total += cost[i - 1];
            }
        }

        total
    }
}
