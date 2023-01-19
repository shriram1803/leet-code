class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target == "0000") return 0;
        queue<pair<string, int>> q;
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if(dead.count("0000")) return -1;
        unordered_set<string> vis;
        q.push({"0000", 0}), dead.insert("0000");
        while(!q.empty()) {
            string curr = q.front().first;
            int cnt = q.front().second;
            if(curr == target) return cnt;
            q.pop();
            for(int i = 0; i < 4; ++i) {
                string temp = curr, temp1 = curr;
                if(temp[i] == '0') 
                    temp[i] = '9';
                else
                    temp[i] = temp[i] - 1;
                   
                if(temp1[i] == '9')
                    temp1[i] = '0';
                else
                    temp1[i] = temp1[i] + 1;
                
                if(!dead.count(temp)) q.push({temp, cnt + 1}), dead.insert(temp);
                if(!dead.count(temp1)) q.push({temp1, cnt + 1}), dead.insert(temp1);
            }
        }
        return -1;
    }
};