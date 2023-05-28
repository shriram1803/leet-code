//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  const int mod = (int)(1e9 + 7);
  int f(int curr, int ind, vector<int>& arr, vector<vector<int>>& dp) {
      if(ind == 0) {
          return (curr == 0) + (curr == arr[0]);
      }
      
      if(dp[ind][curr] != -1) return dp[ind][curr];
      
      int not_pick = f(curr, ind - 1, arr, dp);
      int pick = 0;
      if(curr >= arr[ind]) pick += f(curr - arr[ind], ind - 1, arr, dp);
      
      return dp[ind][curr] = (not_pick + pick) % mod;
  }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int s = accumulate(arr.begin(), arr.end(), 0);
        
        if((s - d) < 0 or (s - d) % 2) return 0;
        
        vector<vector<int>> dp(n, vector<int>(s + 1, -1));
        
        return f((s - d) / 2, n - 1, arr, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends