class Solution {
public:
    long long solve(vector<int>& nums, int minn, int maxx) {
        
        long long local = 0;
        int lastMin = -1, lastMax = -1;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == minn) {
                lastMin = i;
            }
            if(nums[i] == maxx) {
                lastMax = i;
            }
            if(lastMin != -1 and lastMax != -1)
                local += min(lastMin, lastMax) + 1;
        }
        return local;
        
    }
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        long long res = 0;
        
        nums.emplace_back(INT_MAX);
        
        vector<int> temp;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] < minK or nums[i] > maxK) {
                res += solve(temp, minK, maxK);
                temp.resize(0);
            } else {
                temp.emplace_back(nums[i]);
            }
        }
        
        return res;
        
    }
};