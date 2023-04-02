class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        set<int> s(spells.begin(), spells.end());
        unordered_map<int, int> resTable;
        vector<int> res(spells.size());
        sort(potions.begin(), potions.end(), greater<int>());
        int ind = 0, n = potions.size();
        for(auto& it : s) {
            while(ind < n and potions[ind] * (long long)it >= success)
                ind += 1;
            resTable[it] = ind;
        }
        for(int i = 0; i < spells.size(); ++i) {
            spells[i] = resTable[spells[i]];
        }
        return spells;
    }
};