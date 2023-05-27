//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int backtrack(int curr, int ind, int nums[], vector<vector<int>>& dp) {
        if(ind == 0) {  
            return curr == nums[ind];
        }
        if(curr < 0)
            return 0;
        
        if(dp[ind][curr] != -1) 
            return dp[ind][curr];
        
        int pick = backtrack(curr - nums[ind], ind - 1, nums, dp);
        int not_pick = backtrack(curr, ind - 1, nums, dp);
        
        return dp[ind][curr] = pick | not_pick;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int s = 0;
        for(int i = 0; i < N; ++i) s += arr[i];
        if(s % 2 == 1) 
            return 0;
        int target = s / 2;
        vector<vector<int>> dp(N, vector<int>(target + 1, -1));
        return backtrack(target, N - 1, arr, dp);
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