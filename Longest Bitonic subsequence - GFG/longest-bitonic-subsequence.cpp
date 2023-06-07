//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void LIS(vector<int>& nums, vector<int>& dp) {
        
        int n = nums.size();
        
        for(int ind = 1; ind < n; ++ind) {
            for(int prev_ind = 0; prev_ind < ind; ++prev_ind) {
                if(nums[ind] > nums[prev_ind]) 
                    dp[ind] = max(dp[ind], 1 + dp[prev_ind]);
            }
        }
    }
    void LDS(vector<int>& nums, vector<int>& dp) {
        
        int n = nums.size();
        
        for(int ind = n - 1; ind >= 0; --ind) {
            for(int prev_ind = n - 1; prev_ind > ind; --prev_ind) {
                if(nums[ind] > nums[prev_ind]) 
                    dp[ind] = max(dp[ind], 1 + dp[prev_ind]);
            }
        }
        
    }
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n= nums.size();
	    vector<int> lisDP(n + 1, 1), ldsDP(n + 1 , 1);
	    LIS(nums, lisDP), LDS(nums, ldsDP);
	    
	    int res = 1;
	    
	    for(int i = 0; i <= n; ++i) {
	        res = max(res, lisDP[i] + ldsDP[i] - 1);
	    }
	    
	    return res;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends