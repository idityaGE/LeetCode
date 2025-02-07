use std::collections::HashMap;

impl Solution {
    pub fn query_results(limit: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut key_to_value = HashMap::new();
        let mut value_count = HashMap::new();
        let mut result = Vec::new();
        let mut cnt =0;

        for query in queries {
            let key = query[0];
            let value = query[1];

            if let Some(&old_value) = key_to_value.get(&key) {
                if let Some(count) = value_count.get_mut(&old_value) {
                    *count -= 1;
                    if *count == 0 {
                        cnt -= 1;
                    } 
                }
            }

            key_to_value.insert(key,value);
            let count = value_count.entry(value).or_insert(0);

            if *count == 0 {
                cnt += 1;
            }
            *count += 1;
            result.push(cnt);
        }

        return result;
    }
}