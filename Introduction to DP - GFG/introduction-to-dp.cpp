//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
const int MOD = 1000000007;
class Solution {
  public:
  int f(long long n, vector<long long>& dp) {
      if(n <= 1) return n;
      if(dp[n] != -1) return dp[n];
      return dp[n] = (f(n - 1, dp) % MOD + f(n - 2, dp) %  MOD) % MOD; 
  }
    long long int topDown(int n) {
        // code here
        vector<long long> dp(n + 1, -1);
        return f(n, dp) % MOD;
    }
    long long int bottomUp(int n) {
        // code here
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends