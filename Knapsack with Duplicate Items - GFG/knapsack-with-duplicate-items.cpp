//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(W + 1, 0));
        
        for(int i = 0; i <= W; ++i)
            dp[0][i] = (i / wt[0]) * val[0];
            
        for(int ind = 1; ind < N; ++ind) {
            for(int curr = 0; curr <= W; ++curr) {
                int not_pick = dp[ind - 1][curr];
                int pick = -1e9;
                if(curr >= wt[ind])
                    pick = val[ind] + dp[ind][curr - wt[ind]];
                dp[ind][curr] = max(not_pick, pick);
            }
        }
        
        return dp[N - 1][W];
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