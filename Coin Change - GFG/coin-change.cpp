//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int n, int amount) {

        vector<long long> prev(amount + 1, 0), curr(amount + 1, 0);
        
        for(int i = 0; i <= amount; i += coins[0]) {
            prev[i] = 1;
        }
        
        for(int ind = 1; ind < n; ++ind) {
            for(int amt = 0; amt <= amount; ++amt) {
                long long not_pick = prev[amt];
                long long pick = 0;
                if(amt >= coins[ind])
                    pick += curr[amt - coins[ind]];
                curr[amt] = (not_pick + pick);
            }
            prev = curr;
        }
        
        return prev[amount];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends