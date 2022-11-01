class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> res(n, -1);
        for(int i = 0; i < n; ++i){
            bool reached = true;
            int j = 0, k = i;
            while(reached and j < m and k < n){
                int t = grid[j][k];
                if(t == 1){
                    if(k == n - 1){
                        reached = false;
                        break;
                    } else {
                        if(grid[j][k + 1] == -1){
                            reached = false;
                            break;
                        }
                    }
                    k++;
                }else{
                    if(k == 0){
                        reached = false;
                        break;
                    } else {
                        if(grid[j][k - 1] == 1){
                            reached = false;
                            break;
                        }
                    }
                    k--;
                }
                j++;
            }
            if(reached) res[i] = k;
        }
        return res;
    }
};