class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int left, right, mid, best;
        for(int i = 0, n = potions.size(); i < spells.size(); ++i) {
            left = 0, right = n - 1, best = n;
            while(left <= right) {
                mid = left + (right - left) / 2;
                if(potions[mid] * (long long)spells[i] >= success) {
                    right = mid - 1;
                    best = mid;
                } else {
                    left = mid + 1;
                }
            }
            spells[i] = n - best;
        }
        return spells;
    }
};