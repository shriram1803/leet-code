class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        priority_queue<pair<int, int>> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> picked;
        long long su = 0;
        long long res = -1;
        
        for(int i = 0; i < n; ++i) {
            pq.push({nums1[i], nums2[i]});
        }        
        
        while(!pq.empty()) {
            su += pq.top().first;
            picked.push({pq.top().second, pq.top().first});
            pq.pop();
            if(picked.size() == k) {
                res = max(res, su * picked.top().first);
                su -= picked.top().second;
                picked.pop();
            }
        }
        
        return res;
    }
};