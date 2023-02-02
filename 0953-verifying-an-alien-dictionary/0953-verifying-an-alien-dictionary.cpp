class Solution {
public:
    bool check(string curr, string prev, vector<int>& pos) {
        if(curr == prev) return true;
        if(curr.size() < prev.size() and prev.substr(0, curr.size()) == curr) 
            return false;
        for(int i = 0; i < prev.size(); ++i) {
            if(pos[prev[i] - 'a'] > pos[curr[i] - 'a'])
                return false;
            else if(pos[prev[i] - 'a'] < pos[curr[i] - 'a'])
                return true;
        }
       
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size() == 1) return true;
        vector<int> pos(26, 0);
        for(int i = 0; i < order.size(); ++i) {
            pos[order[i] - 'a'] = i;
        }
        for(int i = 1; i < words.size(); ++i) {
            if(!check(words[i], words[i - 1], pos))
                return false;
        }
        return true;
    }
};