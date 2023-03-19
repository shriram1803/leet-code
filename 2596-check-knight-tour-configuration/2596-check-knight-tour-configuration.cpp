class Solution {
public:
    vector<vector<int>> moves{
        {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}
    };
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int x = 0, y = 0, curr = 0;
        int visited = 1;
        int nextX, nextY;
        while(visited < n * n) {
            bool found = false;
            for(int i = 0; i < 8; ++i) {
                nextX = x + moves[i][0], nextY = y + moves[i][1];
                if(nextX < 0 or nextY < 0 or nextX >= n or nextY >= n) 
                    continue;
                if(grid[nextX][nextY] == curr + 1) {
                    found = true;
                    x = nextX, y = nextY;
                    break;
                } 
            }
            if(!found) {
                return false;
            }
            curr += 1;
            visited += 1;
        }
        return true;
    }
};