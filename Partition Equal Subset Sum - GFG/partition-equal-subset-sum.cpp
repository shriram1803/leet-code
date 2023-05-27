//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int s = 0;
        for(int i = 0; i < N; ++i) s += arr[i];
        if(s % 2 == 1) 
            return 0;
        int target = s / 2;
        vector<vector<int>> dp(N, vector<int>(target + 1, 0));
        dp[0][arr[0]] = 1;
        
        for(int i = 1; i < N; ++i) {
            for(int j = 1; j <= target; ++j) {
                int not_pick = dp[i - 1][j];
                int pick = 0;
                if(j >= arr[i])
                    pick = dp[i - 1][j - arr[i]];
                dp[i][j] = pick | not_pick;
            }
        }
        
        return dp[N - 1][target];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends