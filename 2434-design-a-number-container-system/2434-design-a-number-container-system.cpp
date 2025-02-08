class NumberContainers {
    unordered_map<int, int> idx_num;
    unordered_map<int, set<int>> num_idx;
public:
    NumberContainers() {}
    
    void change(int index, int number) {
        if(idx_num.count(index)) {
            num_idx[idx_num[index]].erase(index);
            if(num_idx[idx_num[index]].size() == 0)
                num_idx.erase(idx_num[index]);
        }

        num_idx[number].insert(index);
        idx_num[index] = number;
    }
    
    int find(int number) {
        if (!num_idx.count(number)) 
            return -1;
        return *(num_idx[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */