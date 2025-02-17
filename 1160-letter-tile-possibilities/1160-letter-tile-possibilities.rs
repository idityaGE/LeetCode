use std::collections::HashMap;

impl Solution {
    pub fn num_tile_possibilities(tiles: String) -> i32 {
        let mut char_cnt = HashMap::new();
        for ch in tiles.chars() {
            *char_cnt.entry(ch).or_insert(0) += 1;
        }
        Self::find_seq(&mut char_cnt)
    }
    pub fn find_seq(char_cnt: &mut HashMap<char, i32>) -> i32 {
        let mut cnt = 0;

        for (&ch, &freq) in char_cnt.clone().iter() {
            if freq == 0 {
                continue;
            }

            cnt += 1;
            *char_cnt.get_mut(&ch).unwrap() -= 1;
            cnt += Self::find_seq(char_cnt);
            *char_cnt.get_mut(&ch).unwrap() += 1;
        }

        cnt
    }
}