class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> res(n, 0), stack;
        for(int i = n - 1; i >= 0; --i) {
            int cnt = 0;
            while(!stack.empty() and stack.back() < heights[i]) ++cnt, stack.pop_back();
            if(!stack.empty()) ++cnt;
            res[i] = cnt;
            stack.emplace_back(heights[i]);
        }
        return res;
    }
};