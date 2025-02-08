use std::collections::{HashMap, BTreeSet};

struct NumberContainers {
    // Maps index to number
    index_to_num: HashMap<i32, i32>,
    // Maps number to set of indices
    num_to_indices: HashMap<i32, BTreeSet<i32>>,
}

impl NumberContainers {
    fn new() -> Self {
        NumberContainers {
            index_to_num: HashMap::new(),
            num_to_indices: HashMap::new(),
        }
    }
    
    fn change(&mut self, index: i32, number: i32) {
        // If index already has a number, remove it from the old number's set
        if let Some(&old_num) = self.index_to_num.get(&index) {
            if let Some(indices) = self.num_to_indices.get_mut(&old_num) {
                indices.remove(&index);
                if indices.is_empty() {
                    self.num_to_indices.remove(&old_num);
                }
            }
        }
        
        // Add new number
        self.index_to_num.insert(index, number);
        self.num_to_indices
            .entry(number)
            .or_insert_with(BTreeSet::new)
            .insert(index);
    }
    
    fn find(&self, number: i32) -> i32 {
        // Return minimum index for the number if it exists, otherwise -1
        self.num_to_indices
            .get(&number)
            .and_then(|indices| indices.first())
            .copied()
            .unwrap_or(-1)
    }
}