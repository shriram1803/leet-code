//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> dirs{-1, 0, 1, 0, -1};
    void dfs(vector<vector<int>>& g, int r, int c, int target, int color) {
        if(r < 0 or c < 0 or r >= g.size() or c >= g[0].size() or g[r][c] != target) return;
        g[r][c] = color;
        for(int i = 0; i <= 3; ++i) {
            dfs(g, r + dirs[i], c + dirs[i + 1], target, color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        if(image[sr][sc] == newColor) return image;
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends