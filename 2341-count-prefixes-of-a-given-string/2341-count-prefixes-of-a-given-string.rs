impl Solution {
    pub fn count_prefixes(words: Vec<String>, s: String) -> i32 {
        let mut cnt = 0;
        let n = s.len();
        let s_bytes = s.as_bytes();

        for st in &words {
            if st.len() > n {
                continue;
            }

            let st_bytes = st.as_bytes();
            let mut is_prefix = true;

            for i in 0..st.len() {
                if st_bytes[i] != s_bytes[i] {
                    is_prefix = false;
                    break;
                }
            }

            if is_prefix {
                cnt += 1;
            }
        }

        cnt
    }
}
