class Solution {
public:
    void backtrack(string& s, string curr, int ind, int n, int dot_cnt, vector<string>& res) {
        if(dot_cnt < -1) return;
        if(ind == n and dot_cnt == -1) {
            curr.pop_back();
            res.push_back(curr);
            return;
        }
        string x = "";
        for(int i = ind, j = i + 3; i < n and i <= j; ++i) {
            x += s[i];
            if(stoi(x) > 255) 
                return;           
            backtrack(s, curr + x + ".", i + 1, n, dot_cnt - 1, res);
            if(x == "0") return;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> res;
        backtrack(s, "", 0, n, 3, res);
        return res;
    }
};