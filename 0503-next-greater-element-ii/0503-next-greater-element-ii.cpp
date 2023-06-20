class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i = 0; i < 2*n; ++i) {
            while(!s.empty() and nums[s.top() % n] < nums[i % n]) {
                m[s.top() % n] = nums[i % n];
                s.pop();
            }
            s.push(i);
        }
        for(int i = 0; i < n; ++i) {
            if(m.count(i))
                nums[i] = m[i];
            else 
                nums[i] = -1;
        }
        return nums;
    }
};