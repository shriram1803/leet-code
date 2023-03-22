class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n; ++i) {
            pq.push({nums[i], i});
        }
        while(!pq.empty()) {
            int curr_ind = pq.top().second;
            if(nums[curr_ind] == -1) {
                pq.pop();
            } else {
                nums[curr_ind] == -1;
                if(curr_ind > 0)
                    nums[curr_ind - 1] = -1;
                if(curr_ind < n - 1)
                    nums[curr_ind + 1] = -1;
                res += pq.top().first;
                pq.pop();
            }
        }
        return res;
    }
};