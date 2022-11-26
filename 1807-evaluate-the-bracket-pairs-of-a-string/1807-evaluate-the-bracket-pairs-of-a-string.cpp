class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res = "";
        unordered_map<string, string> m;
        for(auto& prs : knowledge) {
            m[prs[0]] = prs[1];
        }
        const int n = s.size();
        int i = 0;
        while(i < n) {
            if(s[i] != '(') {
                res += s[i];
            } else {
                string temp = "";
                while(++i < n and s[i] != ')') temp += s[i];
                if(m.find(temp) == m.end()) res += '?';
                else res += m[temp];
            }
            ++i;
        }
        return res;
    }
};