use std::collections::HashMap;

impl Solution {
    pub fn total_fruit(fruits: Vec<i32>) -> i32 {
        let mut fruit_count: HashMap<i32, i32> = HashMap::new();
        let (mut max_len, mut left) = (0, 0);

        for (right, &fruit) in fruits.iter().enumerate() {
            *fruit_count.entry(fruit).or_insert(0) += 1;

            if fruit_count.len() > 2 {
                *fruit_count.entry(fruits[left]).or_default() -= 1;
                if fruit_count[&fruits[left]] == 0 {
                    fruit_count.remove(&fruits[left]);
                }
                left += 1;
            }

            max_len = max_len.max(right - left + 1);
        }

        max_len as i32
    }
}