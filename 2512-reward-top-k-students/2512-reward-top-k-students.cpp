typedef pair<int, int> pr;
class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        int n = report.size();
        unordered_set<string> pos(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> neg(negative_feedback.begin(), negative_feedback.end());
        
        auto comp = [](const pr a, const pr b) {
            return a.first < b.first or (a.first == b.first and a.second > b.second);
        };
        
        priority_queue<pr, vector<pr>, decltype(comp)> pq(comp);
        vector<int> res(k);
        for(int i = 0; i < n; ++i) {
            int points = 0;
            istringstream ss(report[i]); 
            string word;
            while (ss >> word)
            {
                if(pos.count(word)) {
                    points += 3;
                } else if(neg.count(word)) {
                    points -= 1;
                }
            }
            pq.push({points, student_id[i]});
        }
        for(int i = 0; i < k; ++i) {
            res[i] = pq.top().second, pq.pop();
        }
        return res;
    }
};