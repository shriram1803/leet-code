class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        queue<pair<int, int>> q;
        for(int i = 0; i < manager.size(); ++i) {
            if(manager[i] == -1) continue;
            adj[manager[i]].emplace_back(i);
        }
        int time = 0;
        q.push({headID, 0});
        while(!q.empty()) {
            int temp = q.front().first, tmp = q.front().second;
            q.pop();
            time = max(time, tmp);
            for(int val : adj[temp]) {
                q.push({val, tmp + informTime[temp]});
            }
        }
        return time;
    }
};