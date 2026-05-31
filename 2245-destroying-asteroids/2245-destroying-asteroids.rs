impl Solution {
    pub fn asteroids_destroyed(mass: i32, mut asteroids: Vec<i32>) -> bool {
        asteroids.sort_unstable();
        
        let mut current_mass = mass as i64;
        
        for asteroid in asteroids {
            let ast_mass = asteroid as i64;
            
            if current_mass < ast_mass {
                return false;
            }
            
            current_mass += ast_mass;
        }
        
        true
    }
}