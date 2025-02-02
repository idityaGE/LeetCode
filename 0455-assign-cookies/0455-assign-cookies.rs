impl Solution {
    pub fn find_content_children(mut g: Vec<i32>, mut s: Vec<i32>) -> i32 {
        g.sort(); // Sort greed factors
        s.sort(); // Sort cookie sizes

        let (mut p, mut i) = (0, 0); // p -> children, i -> cookies

        while p < g.len() && i < s.len() {
            if g[p] <= s[i] {
                p += 1; // Move to next child
            }
            i += 1; // Move to next cookie
        }

        p as i32 // Number of content children
    }
}
