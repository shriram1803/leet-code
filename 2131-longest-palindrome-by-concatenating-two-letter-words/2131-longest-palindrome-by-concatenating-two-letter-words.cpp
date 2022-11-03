class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res = 0, cnt_odd_double = 0, max_odd_double = 0;
        unordered_map<string, int> m;
        bool hasDouble = false;
        for(auto& word : words){
            string x = word;
            reverse(x.begin(), x.end());
            if(x == word) {
                if(m[word] % 2 == 1) cnt_odd_double++;
                else cnt_odd_double--;
            }
            if(m[word]){
                res += 4;
                m[word]--;                
            }else{
                m[x]++;
            }
        }
        if(cnt_odd_double) res += 2;
        return res;
    }
};