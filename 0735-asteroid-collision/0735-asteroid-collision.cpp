class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        
        for(int a : asteroids) {
            if(a > 0) {
                res.emplace_back(a);
            } else {
                while(!res.empty() and res.back() > 0 and res.back() < abs(a))
                    res.pop_back();
                if(!res.empty() and res.back() == abs(a))
                    res.pop_back();
                else if(res.empty() or res.back() < 0)
                    res.emplace_back(a);
            }
        }
        
        return res;
    }
};