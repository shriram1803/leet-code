class Solution {
public:
    int nearestExit(vector<vector<char>>& mz, vector<int>& e) {
        const int m = mz.size(), n = mz[0].size();
        int dirs[] = {0, -1, 0, 1, 0};
        
        deque<array<int, 3>> dq = {{e[0], e[1], 0}};
        
        while(!dq.empty()) {
            auto [x, y, d] = dq.front();
            dq.pop_front();
            for(int i = 0; i < 4; ++i) {
                int cx = x + dirs[i], cy = y + dirs[i + 1];
                if(cx < 0 or cy < 0 or cx >= m or cy >= n or mz[cx][cy] == '+')
                    continue;
                mz[cx][cy] = '+';
                if((cx != e[0] or cy != e[1]) and (cx*cy == 0 or cx == m-1 or cy == n-1))
                    return d + 1;
                dq.push_back({cx, cy, d + 1});
            }
        }
        return -1;
    }
};