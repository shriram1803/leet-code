class Solution {
public:
    bool ifAllCapital(string word) {
        for(auto ch : word) {
            if(ch >= 97) 
                return false;
        }
        return true;
    }
    bool ifAllSmall(string word) {
        int n = word.size();
        for(int i = 1; i < n; ++i) {
            if(word[i] < 97) 
                return false;
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        return ifAllCapital(word) or ifAllSmall(word);
    }
};