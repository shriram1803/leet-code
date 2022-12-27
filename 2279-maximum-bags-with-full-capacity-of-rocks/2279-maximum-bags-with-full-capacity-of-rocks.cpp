class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int addOns) {
        int cnt = 0, n = capacity.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; ++i) {
            int val = capacity[i] - rocks[i];
            if(val > 0) {
                pq.push(val);
            } else {
                ++cnt;
            }
        }
        while(!pq.empty() and addOns >= pq.top()) {
            addOns -= pq.top(), pq.pop(), ++cnt;
        }
        return cnt;
    }
};