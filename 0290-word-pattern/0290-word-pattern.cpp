class Solution {
public:
    void createArr(string str, vector<string>& arr) {
        istringstream ss(str);
        string word;
        while (ss >> word)
        {
            arr.emplace_back(word);
        }
    }
    
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        unordered_map<char, string> m;
        unordered_map<string, char> m1;
        vector<string> v;
        createArr(s, v);
        if(n != v.size()) return false;
        for(int i = 0; i < n; ++i) {
            if(m.find(pattern[i]) == m.end() and m1.find(v[i]) == m1.end()) {
                m[pattern[i]] = v[i]; 
                m1[v[i]] = pattern[i];
            } else if(m.find(pattern[i]) != m.end() and m1.find(v[i]) != m1.end()) {
                if(m[pattern[i]] != v[i] or m1[v[i]] != pattern[i])
                    return false;
            } else {
                return false;
            }
        }
        return true;
    }
};