class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 2, mid;
        
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(arr[mid + 1] < arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        return left;
    }
};