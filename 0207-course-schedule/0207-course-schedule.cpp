class Solution {
public:
    void dfs(int curr, vector<vector<int>>& g, vector<int>& vis, vector<int>& indegree, int& rem_courses) 
    {
        if(vis[curr] == 1)
            return;
        if(indegree[curr] > 1) {
            indegree[curr] -= 1;
            return;
        }
        
        vis[curr] = 1, rem_courses -= 1;
        
        for(auto& node : g[curr])
            dfs(node, g, vis, indegree, rem_courses);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        int n = prereq.size();
        vector<int> indegree(numCourses);
        vector<int> vis(numCourses);
        vector<vector<int>> g(numCourses);
        
        for(auto& p : prereq) {
            indegree[p[0]] += 1;
            g[p[1]].emplace_back(p[0]);
        }
        
        int rem_courses = numCourses;
        for(int i = 0; i < numCourses; ++i) {
            if(indegree[i] == 0)
                dfs(i, g, vis, indegree, rem_courses);
        }
            
            
        return rem_courses == 0;
    }
};