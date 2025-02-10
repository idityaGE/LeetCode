impl Solution {
    pub fn clear_digits(s: String) -> String {
        let mut stack: Vec<char> = Vec::new();

        for ch in s.chars() {
            if ch.is_digit(10) {
                if !stack.is_empty() {
                    stack.pop();
                }
            } else {
                stack.push(ch);
            }
        }

        stack.iter().collect()
    }
}
