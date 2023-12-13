class SmallestInfiniteSet {
public:
    int smallest;
    unordered_set<int> removed;
    SmallestInfiniteSet() {
        smallest = 1;
    }
    
    int popSmallest() {
        removed.insert(smallest);
        int save = smallest;
        while(removed.count(++smallest));
        return save;
    }
    
    void addBack(int num) {
        if(removed.count(num)) {
            removed.erase(num);
            smallest = min(smallest, num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */