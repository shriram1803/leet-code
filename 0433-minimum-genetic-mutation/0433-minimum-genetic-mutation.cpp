class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> b(bank.begin(), bank.end());
        if(!b.count(end)) return -1;
        queue<pair<string, int>> q;
        q.push({start, 0});
        vector<char> choices{'A', 'C', 'G', 'T'};
        while(!q.empty()) {
            auto [temp, t] = q.front();
            q.pop();
            if(temp == end) return t;
            for(int i = 0; i < 8; ++i){
                for(auto& ch : choices){
                    string tmp = temp;
                    tmp[i] = ch;
                    if(b.count(tmp)){
                        q.push({tmp, t + 1});
                        b.erase(tmp);
                    }
                }
            }
        }
        return -1;
    }
};