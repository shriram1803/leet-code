class MinStack {
public:
    vector<pair<int, int>> stack;
    int n;
    MinStack() {
        n = 0;
    }
    
    void push(int val) {
        stack.push_back({val, val});
        if(n > 0)
            stack[n].second = min(stack[n].second, stack[n - 1].second);
        n += 1;
    }
    
    void pop() {
        stack.pop_back();
        n -= 1;
    }
    
    
    int top() {
        return stack[n - 1].first;
    }
    
    int getMin() {
        return stack[n - 1].second;
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