class MyQueue {
public:
    stack<int> s, temp;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        while(s.size() > 1) {
            temp.push(s.top());
            s.pop();
        }
        int val = s.top();
        s.pop();
        while(!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
        return val;
    }
    
    int peek() {
        while(s.size() > 1) {
            temp.push(s.top());
            s.pop();
        }
        int val = s.top();
        while(!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
        return val;
    }
    
    bool empty() {
        return !s.size();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */