impl Solution {
    pub fn minimum_deletions(s: String) -> i32 {
        let n = s.len();
        let mut a = vec![0; n];
        let mut b = vec![0; n];
        let s_bytes = s.as_bytes();

        a[n - 1] = if s_bytes[n - 1] == b'a' { 1 } else { 0 };
        b[0] = if s_bytes[0] == b'b' { 1 } else { 0 };

        for i in 1..n {
            b[i] = if s_bytes[i] == b'b' {
                b[i - 1] + 1
            } else {
                b[i - 1]
            }
        }

        for i in (0..(n - 1)).rev() {
            a[i] = if s_bytes[i] == b'a' {
                a[i + 1] + 1
            } else {
                a[i + 1]
            }
        }

        let mut min_del = a[0];
        
        for i in 1..n {
            min_del = min_del.min(b[i - 1] + a[i]);
        }
        
        min_del = min_del.min(b[n - 1]);

        min_del
    }
}
