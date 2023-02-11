/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, int> imp;
        unordered_map<int, vector<int>> subs;
        queue<int> q;
        int res = 0;
        for(auto& e : employees) {
            imp[e->id] = e->importance;
            subs[e->id] = e->subordinates;
        }
        q.push(id);
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            res += imp[curr];
            for(int sub : subs[curr]) {
                q.push(sub);
            }
        }
        return res;
    }
};