class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s;
        
        for(int i = 2*n - 1; i >= 0; --i) {
            while(s.size() and s.top() <= nums[i%n]) s.pop();
            if(s.size()) res[i%n] = s.top();
            s.push(nums[i%n]);
        }

        return res;
    }
};