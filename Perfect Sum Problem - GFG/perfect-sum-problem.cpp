//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	const int mod = (int)(1e9 + 7);
	int f(int rem, int ind, int arr[], vector<vector<int>>& dp) {
	    if(ind == 0) {
	        return (rem == 0) + (rem == arr[ind]);
	    }
	    
	    if(dp[ind][rem] != -1) return dp[ind][rem];
	   
	   int not_take = f(rem, ind - 1, arr, dp);
	   int take = 0;
	   if(rem >= arr[ind]) take += f(rem - arr[ind], ind - 1, arr, dp);
	   
	   return dp[ind][rem] = (take + not_take) % mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(sum, n - 1, arr, dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends