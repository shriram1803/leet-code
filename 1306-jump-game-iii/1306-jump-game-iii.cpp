class Solution {
public:
    bool solve(vector<int>& arr, int start, vector<int>& vis) {
        if(start >= arr.size() or start < 0 or vis[start]) return false;
        if(arr[start] == 0) return true;
        ++vis[start];
        return solve(arr, start + arr[start], vis) or solve(arr, start - arr[start], vis);
        
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> visited(arr.size(), 0);
        return solve(arr, start, visited);   
    }
};