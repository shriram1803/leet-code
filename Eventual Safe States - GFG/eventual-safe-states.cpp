//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(vector<int> adj[], vector<int>& v, vector<int>& path, int curr) {
        if(path[curr]) return false;
        if(v[curr] == 1) return true;
        else if(v[curr] == -1) return false;
        path[curr] = 1;
        for(int val : adj[curr]) {
            if(!dfs(adj, v, path, val)){
                v[curr] = -1;
                return false;
            }
        }
        path[curr] = 0;
        v[curr] = 1;
        return true;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> res, vis(V, 0), path(V, 0);
        for(int i = 0; i < V; ++i) {
            if(!vis[i]) {
                dfs(adj, vis, path, i);
            }
        }
        for(int i = 0; i < V; ++i) {
            if(vis[i] == 1)
                res.emplace_back(i);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends