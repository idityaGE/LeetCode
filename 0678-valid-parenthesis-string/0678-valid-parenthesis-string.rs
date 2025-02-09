impl Solution {
    pub fn check_valid_string(s: String) -> bool {
        let (mut low, mut high) = (0, 0);

        for c in s.chars() {
            if c == '(' {
                low += 1;
                high += 1;
            } else if c == ')' {
                low -= 1;
                high -= 1;
            } else { // '*'
                low -= 1;
                high += 1;
            }

            if high < 0 {
                return false; // Too many closing brackets
            }
            if low < 0 {
                low = 0; // '*' can act as empty, so reset low
            }
        }

        low == 0
    }
}
