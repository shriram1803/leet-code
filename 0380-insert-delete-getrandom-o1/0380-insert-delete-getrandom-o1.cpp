class RandomizedSet {
public:
    unordered_map<int, int> m;
    vector<int> v;
    int n;
    RandomizedSet() {
        n = 0;
    }
    
    bool insert(int val) {
        if(m.find(val) == m.end()) {
            m[val] = n++;
            v.emplace_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end()) return false;
        v[m[val]] = v[--n];
        m[v.back()] = m[val];
        v.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        int val = rand() % n;
        return v[val];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */