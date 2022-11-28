class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i = 0, j = 0, n1 = players.size(), n2 = trainers.size();
        while(i < n1 and j < n2) {
            while(j < n2 and trainers[j] < players[i]) ++j;
            if(j < n2) ++i, ++j;
        }
        return i;
    }
};