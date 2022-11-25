class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;
        for(auto task : tasks) m[task]++;
        int res = 0;
        for(auto [task, cnt] : m) {
            if(cnt < 2) return -1;
            int rem = cnt % 3;
            if(rem == 0) {
                res += cnt / 3;
            } else if(rem == 1) {
                res += (((cnt - 4) / 3) + 2);
            } else {
                res += ((cnt / 3) + (cnt % 3) / 2);
            }
        }
        return res;
    }
};