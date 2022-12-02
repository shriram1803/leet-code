class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        vector<int> freq1(26, 0), freq2(26, 0);
        priority_queue<int> p, q;
        for(auto ch : word1) freq1[ch - 'a']++;
        for(auto ch : word2) freq2[ch - 'a']++;
        for(int i = 0; i < 26; ++i) {
            if(freq1[i] == 0 and freq2[i] == 0) continue;
            if(freq1[i] == 0 or freq2[i] == 0) return false;
            p.push(freq1[i]);
            q.push(freq2[i]);
        }
        while(!p.empty() or !q.empty()) {
            if(p.empty() or q.empty() or p.top() != q.top()) return false;
            p.pop(), q.pop();
        } 
        return true;
    }
};