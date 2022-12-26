class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start >= arr.size() or start < 0 or arr[start] < 0) return false;
        if(arr[start] == 0) return true;
        arr[start] = -arr[start];
        return canReach(arr, start + arr[start]) or canReach(arr, start - arr[start]); 
    }
};