class SmallestInfiniteSet {
public:
    set<int> s;
    int n;
    SmallestInfiniteSet() {
        n = 1;
    }
    
    int popSmallest() {
        if(!s.empty()) {
            int ret = *s.begin();
            s.erase(ret);
            return ret;
        }
        return n++;
    }
    
    void addBack(int num) {
        if(num < n)
            s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */