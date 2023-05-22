class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.emplace_back(INT_MAX);
        int cont = 1, prev = INT_MIN;
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int num : nums) {
            if(num == prev)
                cont += 1;
            else {
                pq.push({cont, prev});
                if(pq.size() > k)
                    pq.pop();
                prev = num, cont = 1;
            }
        }
        if(pq.top().second == INT_MIN)
            pq.pop();
        while(!pq.empty())
            res.emplace_back(pq.top().second), pq.pop();
        return res;
    }
};