class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> m;
    vector<int> v;
    int n;
    RandomizedCollection() {
        n = 0;
    }
    
    bool insert(int val) {
        m[val].insert(n++);
        v.emplace_back(val);
        if(m[val].size() > 1) {
            return false;
        }
        return true;
    }
    
    bool remove(int val) {
        if(!m[val].size()) return false;
        
        if(val == v.back()) {
            v.pop_back();
            m[val].erase(--n);
            return true;
        }
        
        int val_ind = *m[val].begin();
        v[val_ind] = v[--n];
        v.pop_back();
        
        int swappedVal = v[val_ind];
        m[swappedVal].erase(n);
        m[swappedVal].insert(val_ind);
        m[val].erase(val_ind);
        
        return true;
    }
    
    int getRandom() {
        int pick = rand() % n;
        return v[pick];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */