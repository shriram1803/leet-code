class Solution {
public:
    bool canReachOffice(int& speed, vector<int>& dist, double& hour) {
        double curr = 0;
        for(int d : dist) {
            curr += (double)d/speed;
            if(curr > hour) 
                return 0;
            curr = ceil(curr);
        }
        return 1;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1;
        int right = 1e7;
        int mid;
        int ans = -1;
        
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(canReachOffice(mid, dist, hour)) 
                ans = mid, right = mid - 1;
            else
                left = mid + 1;
        }
        
        return ans;
    }
};