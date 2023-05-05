class MinStack {
public:
    map<int, vector<int>> mp;
    int last;
    MinStack() {
        
    }
    
    void push(int val) {
        mp[val].emplace_back(last);
        last = val;
    }
    
    void pop() {
        int prev = mp[last].back();
        mp[last].pop_back();
        if(!mp[last].size())
            mp.erase(last);
        last = prev;
    }
    
    int top() {
        return last;
    }
    
    int getMin() {
        return (*mp.begin()).first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */