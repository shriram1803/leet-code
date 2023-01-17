//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[], vector<int>& v, vector<int>& path, int curr) {
        if(path[curr]) return true;
        if(v[curr]) return false;
        v[curr] = 1;
        path[curr] = 1;
        for(int val : adj[curr]) {
            if(dfs(adj, v, path, val))
                return true;
        }
        path[curr] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V, 0), path(V, 0);
        for(int i = 0; i < V; ++i) {
            if(!vis[i]) {
                if(dfs(adj, vis, path, i))
                    return true;
            }
        }
        return false;
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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends