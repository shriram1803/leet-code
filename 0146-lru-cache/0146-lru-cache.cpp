class DLL {
public:
    int val;
    int key;
    DLL* next;
    DLL* prev;
public:
    DLL(int key, int val) {
        this->key = key;
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class LRUCache {
public:
    unordered_map<int, DLL*> m;
    int capacity;
    DLL *head, *tail;
    
    LRUCache(int cap) {
        capacity = cap;
        head = new DLL(0, 0);
        tail = new DLL(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    void remove_node(DLL* node) {
        auto pre = node->prev;
        auto nxt = node->next;
        pre->next = nxt;
        nxt->prev = pre;
    } 
    
    void add_tail(DLL* node) {
        auto pre = tail->prev;
        auto nxt = tail;
        pre->next = node;
        node->prev = pre;
        node->next = nxt;
        nxt->prev = node;
    }
    
    int get(int key) {
        if(m.count(key)) {
            auto curr = m[key];
            remove_node(curr);
            add_tail(curr);
            return m[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.count(key)) {
            auto curr = m[key];
            remove_node(curr);
            add_tail(curr);
            m[key]->val = value;
            return;
        }
        if(capacity == 0) {
            auto curr = head->next;
            remove_node(curr);
            m.erase(curr->key);
            delete curr;
        } else {
            capacity -= 1;
        }
        auto curr = new DLL(key, value);
        add_tail(curr);
        m[key] = curr;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */