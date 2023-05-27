//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<int> prev(sum + 1, 0), curr(sum + 1, 0);
        if(arr[0] <= sum)
            prev[arr[0]] = 1;
        for(int i = 1; i < n; ++i) {
            curr[0] = 1;
            for(int j = 1; j <= sum; ++j) {
                int notpick = prev[j];
                int pick = false;
                if(arr[i] <= j) pick = prev[j - arr[i]];
                curr[j] = pick || notpick;
            }
            prev = curr;
        }
        return prev[sum];
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