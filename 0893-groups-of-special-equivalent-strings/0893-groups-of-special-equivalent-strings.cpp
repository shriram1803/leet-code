class Solution {
public:
    void fillEvenOdd(string s, string& odd, string& even) {
        for(int i = 0; i < s.size(); ++i) {
            if(i % 2) odd += s[i];
            else even += s[i];
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
    }
    int numSpecialEquivGroups(vector<string>& words) {
        set<pair<string, string>> s;
        for(auto& word : words) {
            string odd = "";
            string even = "";
            fillEvenOdd(word, odd, even);
            s.insert({odd, even});
        }
        return s.size();
    }
};