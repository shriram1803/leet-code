class Solution {
public:
    bool can(vector<int>& c, int h) {
        int cnt = 0;
        for(int num : c) {
            if(cnt == h)
                return 1;
            if(num >= h)
                cnt += 1;
        }
        return cnt == h;
    }
    int hIndex(vector<int>& c) {
        sort(c.begin(), c.end(), greater<int>());
        
        int left = 0;
        int right = c.front();
        int mid;
        int ans = 0;
        
        while(left <= right) {
            mid = left + (right - left) / 2;
            
            if(can(c, mid))
                ans = mid, left = mid + 1;
            else
                right = mid - 1;
            
        }
        
        return ans;
    }
};