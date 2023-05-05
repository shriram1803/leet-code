class MinStack {
public:
    map<int, int> mp;
    vector<int> stack;
    MinStack() {
        
    }
    
    void push(int val) {
        mp[val] += 1;
        stack.push_back(val);
    }
    
    void pop() {
        mp[stack.back()] -= 1;
        if(!mp[stack.back()])
            mp.erase(stack.back());
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        auto val = *mp.begin();
        return val.first;
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