//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    const int mod = (int)(1e9 + 7);
    int totalWays(int m, int n, vector<vector<int>>& grid) {
        // Code here
        if(grid[0][0] == 1)
            return 0;
        int dp[101][101] = { 0 };
        dp[1][1] = 1;
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j) 
                if(grid[i - 1][j - 1] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] += (dp[i - 1][j] + dp[i][j - 1]) % mod;
        return dp[m][n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends