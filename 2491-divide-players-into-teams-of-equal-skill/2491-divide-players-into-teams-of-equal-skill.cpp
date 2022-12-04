class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long res = 0;
        
        sort(skill.begin(),skill.end());
        
        int front = 0, back = skill.size() - 1;
        
        int checker = skill[front] + skill[back];
        
        while(front < back)
        {
            if(checker != skill[front] + skill[back])
                return -1;
            res += skill[front++]*skill[back--];
        }
            
        return res;
    }
};