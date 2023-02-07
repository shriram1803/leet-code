class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m;
        int s = 0, e = 0, n = fruits.size(), res = 0;
        while(e < n) {
            ++m[fruits[e++]];
            if(m.size() <= 2) {
                res = max(res, e - s);
                continue;
            }
            while(s < e and m.size() > 2) {
                --m[fruits[s]];
                if(m[fruits[s]] == 0) {
                    m.erase(fruits[s]);
                }
                ++s;
            }
        }
        return res;
    }
};