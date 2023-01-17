//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void topoSort(vector<vector<pair<int, int>>>& adj, vector<int>& vis, vector<int>& st, int curr) {
        if(vis[curr]) return;
        vis[curr] = 1;
        for(auto pr : adj[curr]) {
            topoSort(adj, vis, st, pr.first);
        }
        st.push_back(curr);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int, int>>> adj(N);
        vector<int> st, vis(N, 0), dst(N, -1);
        for(auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        topoSort(adj, vis, st, 0);
        dst[0] = 0;
        while(st.size()) {
            int temp = st.back(); st.pop_back();
            for(auto it : adj[temp]) {
                if(dst[it.first] == -1) dst[it.first] = dst[temp] + it.second;
                else dst[it.first] = min(dst[it.first], dst[temp] + it.second);
            }
        }
        return dst;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends