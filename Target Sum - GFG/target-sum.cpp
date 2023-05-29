//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  int f(int curr, int ind, vector<int>& arr, vector<vector<int>>& dp) {
      if(ind == 0) {
          return (curr == 0) + (curr == arr[0]);
      }
      
      if(dp[ind][curr] != -1) return dp[ind][curr];
      
      int not_pick = f(curr, ind - 1, arr, dp);
      int pick = 0;
      if(curr >= arr[ind]) pick += f(curr - arr[ind], ind - 1, arr, dp);
      
      return dp[ind][curr] = (not_pick + pick);
  }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int s = accumulate(arr.begin(), arr.end(), 0);
        
        if((s - d) < 0 or (s - d) % 2) return 0;
        
        vector<vector<int>> dp(n, vector<int>(s + 1, -1));
        
        return f((s - d) / 2, n - 1, arr, dp);
    }
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        return countPartitions(A.size(), target, A);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends