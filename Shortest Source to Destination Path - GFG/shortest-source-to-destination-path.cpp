//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<int> dirs{-1, 0, 1, 0, -1};
//   int dfs(vector<vector<int>>& A, int r, int c, int X, int Y) {
//       int N = A.size(), M = A[0].size();
//       if(r < 0 or c < 0 or r >= N or c >= M or A[r][c] == 0) return -1;
//       if(r == X and c == Y) return 0;
//       A[r][c] = 0;
//       int res = INT_MAX;
//       for(int i = 0; i <= 3; ++i) {
//           int ret = dfs(A, r + dirs[i], c + dirs[i + 1], X, Y);
//           if(ret > -1) res = min(res, ret); 
//       }
//       A[r][c] = 1;
//       if(res == INT_MAX) return -1;
//       return 1 + res;
//   }
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0] == 0 or A[X][Y] == 0) return -1;
        // return dfs(A, 0, 0, X, Y);
        int level = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        bool found = false;
        
        while(!q.empty()) {
            int t = q.size();
            ++level;
            while(t--) {
                auto temp = q.front(); q.pop();
                int x = temp.first, y = temp.second;
                for(int i = 0; i <= 3; ++i) {
                    int r = x + dirs[i], c = y + dirs[i + 1];
                    if(r < 0 or c < 0 or r >= N or c >= M or A[r][c] == 0) continue;
                    if(r == X and c == Y) {
                        found = true;
                        break;
                    }
                    A[r][c] = 0;
                    q.push({r, c});
                }
            }
            if(found) break;
        }
        return found ? level : -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends