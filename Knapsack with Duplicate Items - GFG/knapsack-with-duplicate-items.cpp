//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int ind, int curr, int wt[], int val[], vector<vector<int>>& dp) {
        if(ind == 0) {
            return (curr / wt[0]) * val[0];
        }
        
        if(dp[ind][curr] != -1) 
            return dp[ind][curr];
        
        int not_pick = f(ind - 1, curr, wt, val, dp);
        int pick = -1e9;
        if(curr >= wt[ind])
            pick = val[ind] + f(ind, curr - wt[ind], wt, val, dp);
            
        return dp[ind][curr] = max(not_pick, pick);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(W + 1, -1));
        return f(N - 1, W, wt, val, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends