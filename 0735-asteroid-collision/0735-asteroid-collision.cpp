class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        
        for(auto& a : asteroids) {            
            if(a < 0) {
                
                while(!stack.empty() and stack.back() > 0 and stack.back() < -a) 
                    stack.pop_back();
                
                if(!stack.empty() and stack.back() == -a) {
                    stack.pop_back();
                } else {
                    if(stack.empty() or stack.back() < 0)
                        stack.emplace_back(a);
                }  
                
            } else {
                stack.emplace_back(a);
            }
        }
        
        return stack;
    }
};