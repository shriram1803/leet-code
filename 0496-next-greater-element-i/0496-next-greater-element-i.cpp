class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> m;
        for(int num : nums2) {
            while(!s.empty() and s.top() < num) {
                m[s.top()] = num;
                s.pop();
            } 
            s.push(num);
        }
        for(int &num : nums1) {
            if(m.count(num))
                num = m[num];
            else 
                num = -1;
        }
        return nums1;
    }
};