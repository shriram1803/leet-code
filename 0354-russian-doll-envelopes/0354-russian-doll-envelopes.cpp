class Solution {
public:
    static bool customSort(const vector<int>& a, const vector<int>& b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        } else {
            return a[1] > b[1];
        }
    }
    int maxEnvelopes(vector<vector<int>>& envs) {
        int n = envs.size();
        
        sort(envs.begin(), envs.end(), customSort);
        
        vector<int> arr;
        
        for(int i = 0; i < n; ++i) {
            
            // Approach:
            // Idea is to sort the array such that env[i][1] position is sorted in reverse
            // Which makes sure that when some env[i][1] > env[j][1] then always env[i][0] > env[j][0]
            //So we will just consider env[i][1]th positions ans apply LIS
            
            int num = envs[i][1];
            
            //LIS Template
            if(arr.empty() or arr.back() < num) {
                arr.emplace_back(num);
            } else {
                int ind = lower_bound(arr.begin(), arr.end(), num) - arr.begin();
                arr[ind] = num;
            }
        }
        
        return arr.size();
    }
};