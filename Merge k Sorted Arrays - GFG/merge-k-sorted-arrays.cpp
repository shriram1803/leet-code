//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        vector<int> v(k, 0);
        vector<int> res;
        bool cont = true;
        while(cont) {
            cont = false;
            int curr = INT_MAX, id = -1;
            for(int i = 0; i < k; ++i) {
                if(v[i] < k) {
                    cont = true;
                    if(arr[i][v[i]] < curr) {
                        curr = arr[i][v[i]];
                        id = i;
                    }
                }
            }
            if(id != -1) res.emplace_back(curr), ++v[id];
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends