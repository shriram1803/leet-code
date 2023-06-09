//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(N, 1e9));
        for(int i = 0; i < N; ++i) dp[i][i] = 0;
        
        for(int front = N - 1; front > 0; --front) {
            for(int back = front + 1; back < N; ++back) {
                for(int k = front; k < back; ++k) {
                    dp[front][back] = min(dp[front][back], arr[front - 1]*arr[back]*arr[k]+dp[front][k]+dp[k+1][back]);
                }
            }
        }
        
        
        return dp[1][N - 1];

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