class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> v(n);
        priority_queue<int, vector<int>, greater<int>> picked;
        long long su = 0;
        long long res = -1;
        
        for(int i = 0; i < n; ++i) {
            v[i] = {nums2[i], nums1[i]};
        }
        sort(v.rbegin(), v.rend());
        
        for(int i = 0; i < n; ++i) {
            su += v[i].second;
            picked.push(v[i].second);
            
            if(picked.size() > k) {
                su -= picked.top();
                picked.pop();
            }
            
            if(picked.size() == k) {
                res = max(res, su * v[i].first);
            }
        }
        
        return res;
    }
};