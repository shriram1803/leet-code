class Solution {
public:
    bool backtrack(int ind, string curr, string& s, int n, unordered_set<string>& st, vector<unordered_map<string, bool>>& dp)
    {
        if(ind == n)
            return !curr.size();
        
        curr += s[ind];
        
        if(dp[ind].count(curr))
            return dp[ind][curr];
        
        if(st.count(curr)) {
            return dp[ind][curr] = backtrack(ind + 1, "", s, n, st, dp) | backtrack(ind + 1, curr, s, n, st, dp);
        }
        
        return dp[ind][curr] = backtrack(ind + 1, curr, s, n, st, dp);
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        
        vector<unordered_map<string, bool>> dp(s.size()); 
        
        return backtrack(0, "", s, s.size(), st, dp);
    }
};