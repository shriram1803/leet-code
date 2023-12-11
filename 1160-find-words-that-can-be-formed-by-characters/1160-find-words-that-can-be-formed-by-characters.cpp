class Solution {
public:
    bool check(string& target, string& s) {
        int m = target.size() - 1, n = s.size() - 1;
        
        while(m >= 0 and n >= 0) {
            if(target[m] == s[n])
                --m, --n;
            else if(target[m] < s[n])
                return false;
            else
                --m;
        }
        return n < 0;
    }
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        sort(chars.begin(), chars.end());
        
        for(auto& word : words) {
            sort(word.begin(), word.end());
            if(check(chars, word))
                res += word.size();
        }
        
        return res;
    }
};