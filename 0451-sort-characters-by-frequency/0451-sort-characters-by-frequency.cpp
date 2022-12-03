class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        vector<string> bucket(s.size() + 1, "");
        string res = "";
        for(auto ch : s){
            m[ch]++;
        }
        for(auto &[element, count] : m){
            bucket[count].append(count, element);
        }
        for(int i = s.size(); i > 0; --i) {
            if(bucket[i].size())
                res += bucket[i];
        }
        return res;
    }
};