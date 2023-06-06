class Solution {
public:
    bool backtrack(int ind, string& s, int n, vector<string>& dict, vector<int>& dp)
    {
        if(ind == n)
            return 1;
        
        if(dp[ind] != -1)
            return dp[ind];
        
       
        for(auto& word : dict) {
            if(s.substr(ind, word.size()) == word)
                if(backtrack(ind + word.size(), s, n, dict, dp))
                    return dp[ind] = 1;
        }
        
        
        return dp[ind] = 0;
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<int> dp(s.size(), -1); 
        
        return backtrack(0, s, s.size(), wordDict, dp);
    }
};