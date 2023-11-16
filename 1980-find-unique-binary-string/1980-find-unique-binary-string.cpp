class Solution {
public:
    void backtrack(string& curr, int ind, const int n, unordered_set<string>& s, string& res) {
        if(!s.count(curr)) {
            res = curr;
            return;
        }
        for(int i = ind; i < n; ++i) {
            curr[i] = '1';
            backtrack(curr, i + 1, n, s, res);
            curr[i] = '0';
        }
        return;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> s(nums.begin(), nums.end());
        string res = "";
        string curr(n, '0');
        
        backtrack(curr, 0, n, s, res);
        
        return res;
    }
};