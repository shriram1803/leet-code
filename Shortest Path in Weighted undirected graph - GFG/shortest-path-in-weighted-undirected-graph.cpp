//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        vector<int> res(n + 1, INT_MAX), store(n + 1, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        res[1] = 0;
        while(!pq.empty()) {
            auto temp = pq.top(); pq.pop();
            int d = temp.first, curr = temp.second;
            for(auto& it : adj[curr]) {
                int node = it.first, val = it.second;
                if(d + val < res[node]) {
                    store[node] = curr;
                    res[node] = d + val;
                    pq.push({res[node], node});
                }
            }
        }
        if(res[n] == INT_MAX) return {-1};
        vector<int> ans{n};
        int node = n;
        while(node != 1) {
            node = store[node];
            ans.emplace_back(node);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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