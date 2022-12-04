class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long res = 0;
        const int n = skill.size() / 2;
        
        int total = accumulate(skill.begin(), skill.end(), 0);
        
        if(total % n != 0) return -1;
        
        int score_per_team = total / n;
        
        unordered_map<int, int> m;
        
        for(auto val : skill) {
            if(val >= score_per_team) return -1;
            if(m[val]) {
                res += (val * (score_per_team - val));
                m[val]--;
            } else {
                m[score_per_team - val]++;
            }
            
        }
        
        for(auto it : m) if(it.second > 0) return -1;
            
        return res;
    }
};