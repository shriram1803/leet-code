class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> rows(m, 0), cols(n, 0);
        vector<pair<int, int>> save(m * n + 1);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                save[mat[i][j]] = {i, j};
            }
        }
        for(int i = 0; i < m * n; ++i) {
            rows[save[arr[i]].first] += 1;
            cols[save[arr[i]].second] += 1;
            if(rows[save[arr[i]].first] == n or cols[save[arr[i]].second] == m)
                return i;
        }
        return arr.size() - 1;
    }
};