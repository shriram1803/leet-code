//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    vector<int> dp(amount + 1, 100001);
	    dp[0] = 0;
	    for(int i = 1; i <= amount; ++i) {
	        for(auto num : nums) {
	            if(i >= num) dp[i] = min(dp[i], dp[i - num] + 1);
	        }
	    }
	    if(dp[amount] == 100001) return -1;
	    return dp[amount];
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends