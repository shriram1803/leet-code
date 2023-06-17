//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    const int mod = 1003;
    int f(int front, int back, bool isTrue, string& s, vector<vector<vector<int>>>& dp) {
            
        if(front == back) {
            if(s[front] == 'T')
                return isTrue;
            return !isTrue;
        }
        
        if(dp[front][back][isTrue] != -1)
            return dp[front][back][isTrue];

        int res = 0;
        
        for(int k = front + 1; k < back; k += 2) {
            int lt = f(front, k - 1, 1, s, dp), rt = f(k + 1, back, 1, s, dp);
            int lf = f(front, k - 1, 0, s, dp), rf = f(k + 1, back, 0, s, dp);
            if(s[k] == '&') {
                if(isTrue)
                    res += lt * rt;
                else
                    res += lf * rf + lt * rf + lf * rt;
            } else if(s[k] == '|') {
                if(isTrue)
                    res += lt * rt + lt * rf + lf * rt;
                else
                    res += lf * rf;
            } else {
                if(isTrue)
                    res += lt * rf + lf * rt;
                else
                    res += lf * rf + lt * rt;
            }
        }
        
        
        return dp[front][back][isTrue] = res % mod;
        
    }
    int countWays(int N, string S){
        // code here
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(2, -1)));
        return f(0, N - 1, 1, S, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends