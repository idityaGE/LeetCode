impl Solution {
    pub fn number_of_substrings(s: String) -> i32 {
        let mut lastseen = [-1; 3];
        let mut cnt = 0;

        for (i, ch) in s.chars().enumerate() {
            lastseen[(ch as u8 - b'a') as usize] = i as i32;

            if lastseen.iter().all(|&x| x != -1) {
                cnt += 1 + *lastseen.iter().min().unwrap();
            }
        }

        cnt as i32
    }
}