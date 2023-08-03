class Solution {
public:
    vector<string> bank{
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void backtrack(int ind, const int n, string& curr, string& digits, vector<string>& res) {
        
        if(ind == n) {
            if(!curr.empty())
                res.emplace_back(curr);
            return;
        }
        
        for(auto& ch : bank[digits[ind] - '2']) {
            curr.push_back(ch);
            backtrack(ind + 1, n, curr, digits, res);
            curr.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        
        string curr = "";
        backtrack(0, digits.size(), curr, digits, res);
        
        return res;
    }
};