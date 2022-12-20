class Solution {
public:
    void solve(vector<vector<int>>& rooms, vector<bool>& visited, int current){
        if(visited[current]) return;
        visited[current] = 1;
        for(auto& key : rooms[current])
            solve(rooms, visited, key);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, 0);
        solve(rooms, visited, 0);
        for(int i = 0; i < n; ++i){
            if(!visited[i])
                return false;
        }
        return true;
    }
};