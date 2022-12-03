typedef pair<int, char> pr;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        priority_queue<pr> pq;
        string res = "";
        for(auto ch : s){
            m[ch]++;
        }
        for(auto [element, count] : m){
            pq.push({count, element});
        }
        while(!pq.empty()){
            string temp(pq.top().first, pq.top().second);
            pq.pop();
            res += temp;
        }
        return res;
    }
};