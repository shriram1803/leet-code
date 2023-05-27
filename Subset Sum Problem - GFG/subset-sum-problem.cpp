//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int f(int curr, int ind, int n, vector<int>& arr, vector<vector<int>>& dp) {
        if(curr == 0) return 1;
        if(curr < 0 or ind >= n) return 0;
        if(dp[curr][ind] != -1) return dp[curr][ind]; 
        for(int i = ind; i < n; ++i) {
            if(f(curr - arr[i], i + 1, n, arr, dp))
                return 1;
        }
        return dp[curr][ind] = 0;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>> dp(sum + 1, vector<int>(arr.size(), -1));
        return f(sum, 0, arr.size(), arr, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends