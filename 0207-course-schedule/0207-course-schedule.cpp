class Solution {
public:
    void dfs(int curr, vector<vector<int>>& g, vector<int>& vis, vector<int>& indegree, int& courses) 
    {
        if(vis[curr] == 1)
            return;
        
        //Everytime the node is called -> one of it's pre-requisite has been called
        //So, when indegree == 1 -> all of it's pre-requisites have been called
        if(indegree[curr] > 1) {
            indegree[curr] -= 1;
            return;
        }
        
        vis[curr] = 1, courses += 1;
        
        for(auto& node : g[curr])
            dfs(node, g, vis, indegree, courses);
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
        
        int coursesFinished = 0;
        //nodes with indegree=0 means they have no pre-requisites
        for(int i = 0; i < numCourses; ++i) {
            if(indegree[i] == 0)
                dfs(i, g, vis, indegree, coursesFinished);
        }
            
            
        return coursesFinished == numCourses;
    }
};