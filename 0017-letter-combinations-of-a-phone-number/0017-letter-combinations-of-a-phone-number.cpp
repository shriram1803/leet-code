class Solution {
public:
    vector<string> bank{
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void backtrack(int ind, const int n, string& curr, string& digits, vector<string>& res) {
        
        if(ind == n) {
            res.emplace_back(curr);
            return;
        }
        
        for(auto& ch : bank[digits[ind] - '2']) {
            curr[ind] = ch;
            backtrack(ind + 1, n, curr, digits, res);
        }
        
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0)
            return {};
        
        vector<string> res;
        
        string curr = "";
        curr.append(n, '?');
        
        backtrack(0, n, curr, digits, res);
        
        return res;
    }
};