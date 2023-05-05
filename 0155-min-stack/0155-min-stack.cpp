class MinStack {
public:
    vector<pair<int, int>> stack;
    MinStack() {
        
    }
    
    void push(int val) {
        int prev = INT_MAX;
        if(stack.size())
            prev = stack.back().second;
        stack.push_back({val, val});
        stack.back().second = min(stack.back().second, prev);
    }
    
    void pop() {
        stack.pop_back();
    }
    
    
    int top() {
        return stack.back().first;
    }
    
    int getMin() {
        return stack.back().second;
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