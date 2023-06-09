//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int front, int back, int *arr, vector<vector<int>>& dp) {
        if(front == back)
            return 0;
            
        if(dp[front][back] != -1)
            return dp[front][back];
            
        int res = 1e9;
        
        for(int k = front; k < back; ++k) {
            res = min(res, arr[front - 1] * arr[back] * arr[k] + f(front, k, arr, dp) + f(k + 1, back, arr, dp));
        }
        
        return dp[front][back] = res;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return f(1, N - 1, arr, dp);
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends