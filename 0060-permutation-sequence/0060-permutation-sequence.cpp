class Solution {
public:
    int cnt = 0;
    string res;
    void gen(string s, int x) {
        if(cnt == 0)
            return;
        if(x == s.size()) {
            cnt -= 1;
            if(cnt == 0)
                res = s;
            return;
        }
        for(int i = x; i < s.size(); ++i) {
            swap(s[i], s[x]);
            gen(s, x + 1);
        }
    }
    string getPermutation(int n, int k) {
        cnt = k;
        string s = "";
        for(int i = 1; i <= n; ++i) s += to_string(i);
        gen(s, 0);
        return res;   
    }
};