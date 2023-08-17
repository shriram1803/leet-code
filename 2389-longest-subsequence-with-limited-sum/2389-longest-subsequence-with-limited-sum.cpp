class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = queries.size();
        int m = nums.size();
        vector<int> res(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i = 0; i < n; ++i) {
            pq.push({queries[i], i});
        }
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < m; ++i) {
            if(i > 0)
                nums[i] += nums[i - 1];
            while(!pq.empty() and nums[i] > pq.top().first) {
                res[pq.top().second] = i;
                pq.pop();
            }
        }
        while(!pq.empty()) {
            res[pq.top().second] = m;
            pq.pop();
        }
        
        return res;
    }
};