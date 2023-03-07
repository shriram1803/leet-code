class Solution {
public:
    bool check(vector<int>& time, int& required, long long& curr_time) {
        long long trips = 0;
        for(long long t : time) {
            trips += (curr_time / t);
            if(trips >= required)
                return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1, right = 1e14;
        while(left < right) {
            long long mid = (left + right) / 2;
            if(check(time, totalTrips, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};