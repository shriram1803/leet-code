class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        if(s.count(endWord) == 0) return 0;
        queue<pair<string, int>> q;
        int m = beginWord.size();
        q.push({beginWord, 1});
        while(!q.empty()) {
            string curr = q.front().first; int steps = q.front().second; q.pop();
            string temp = curr;
            for(int i = 0; i < m; ++i) {
                for(char j = 'a'; j <= 'z'; ++j) {
                    if(curr[i] == j) continue;
                    temp[i] = (char)j;
                    if(temp == endWord) return steps + 1;
                    if(s.count(temp)) {
                        q.push({temp, steps + 1});
                        s.erase(temp);
                    }
                }
                temp = curr;
            }
        }
        return 0;
    }
};