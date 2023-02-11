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
        unordered_map<int, int> ind;
        queue<int> q;
        int res = 0;
        for(int i = 0; i < employees.size(); ++i) {
            ind[employees[i]->id] = i;
        }
        q.push(id);
        while(!q.empty()) {
            int curr_ind = ind[q.front()]; q.pop();
            res += employees[curr_ind]->importance;
            for(int sub : employees[curr_ind]->subordinates) {
                q.push(sub);
            }
        }
        return res;
    }
};