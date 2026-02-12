use std::collections::HashMap;

impl Solution {
    pub fn longest_balanced(s: String) -> i32 {
        let n = s.len();
        let s_bytes = s.as_bytes();
        let mut max_len = 0;

        for i in 0..n {
            let mut map: HashMap<u8, i32> = HashMap::new();

            for j in i..n {
                let entry = map.entry(s_bytes[j]).or_insert(0);
                *entry += 1;

                let mut iter = map.values();
                let first = iter.next().unwrap();

                let is_balanced = iter.all(|v| v == first);

                if is_balanced {
                    max_len = max_len.max((j - i + 1) as i32);
                }
            }
        }

        max_len
    }
}
