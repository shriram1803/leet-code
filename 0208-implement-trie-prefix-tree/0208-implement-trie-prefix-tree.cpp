class Node {
    public:
        char val;
        unordered_map<char, Node*> children;
        bool isEnd;
    public:
        Node() {
            this->val = '_';
            this->isEnd = false;
        }
        Node(char val) {
            this->val = val;
            this->isEnd = false;
        }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(char ch : word) {
            Node* newNode = new Node(ch);
            if(!curr->children.count(ch))
                curr->children[ch] = newNode;
            curr = curr->children[ch];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(char ch : word) {
            if(!curr->children.count(ch))
                return false;
            curr = curr->children[ch];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(char ch : prefix) {
            if(!curr->children.count(ch))
                return false;
            curr = curr->children[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */