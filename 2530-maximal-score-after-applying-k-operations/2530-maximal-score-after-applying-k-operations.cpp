class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long res = 0;
        priority_queue<int> pq(nums.begin(), nums.end());
        while(k-- and !pq.empty()) {
            int val = pq.top(); pq.pop();
            pq.push(ceil((double)val / 3));
            res += val;
        }
        return res;
    }
};