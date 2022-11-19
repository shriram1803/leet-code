class Solution {
public:
    vector<string> res;
    vector<string> bank{
        "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void solve(string digits, int ind, string current, const int n) {
        if(ind == n) {
            if(current.size()) res.push_back(current);
            return;
        }
        int val = digits[ind] - '2';
        for(auto ch : bank[val]) {
            solve(digits, ind + 1, current + ch, n);
        }
    }
    vector<string> letterCombinations(string digits) {
        solve(digits, 0, "", digits.size());
        return res;
    }
};