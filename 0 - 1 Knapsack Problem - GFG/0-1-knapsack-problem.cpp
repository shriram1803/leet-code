//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int f(int ind, int W, int wt[], int val[], vector<vector<int>>& dp) {
        if(ind == 0) {
            if(W < wt[0]) return 0;
            return val[0];
        }
        
        if(dp[ind][W] != -1) return dp[ind][W];
        
        int not_pick = f(ind - 1, W, wt, val, dp);
        int pick = 0;
        if(wt[ind] <= W) pick += val[ind] + f(ind - 1, W - wt[ind], wt, val, dp);
        
        return dp[ind][W] = max(pick, not_pick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    //   vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    //   return f(n - 1, W, wt, val, dp);
       
       vector<vector<int>> dp(n, vector<int>(W + 1, 0));
       
       for(int i = wt[0]; i <= W; ++i) {
           dp[0][i] = val[0];
       }
       
       for(int i = 1; i < n; ++i) {
           for(int j = 0; j <= W; ++j) {
               
               int not_take = dp[i - 1][j];
               int take = 0;
               if(j >= wt[i]) 
                    take += val[i] + dp[i - 1][j - wt[i]];
                    
                dp[i][j] = max(take, not_take);
           }
       }
       
       return dp[n - 1][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends