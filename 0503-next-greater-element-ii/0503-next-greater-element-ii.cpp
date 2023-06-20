class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> res(n, -1);
        for(int i = 0; i < 2*n; ++i) {
            while(!s.empty() and nums[s.top() % n] < nums[i % n]) {
                res[s.top() % n] = nums[i % n];
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};