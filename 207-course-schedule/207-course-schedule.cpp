class Solution {
public:
    bool dfs(int v, vector<int>& vis, vector<vector<int>>& pr) {
        vis[v] = 2;
        for (int u: pr[v]) {
                if (vis[u] == 2 || v == u) {
                    return false;
                } else if (!vis[u] && !dfs(u,vis,pr)) {
                    return false;
                }
        }
        vis[v] = 1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses,0);
        vector<vector<int>> pr(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            pr[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i] && !dfs(i,vis,pr)) {
                return false;
            }
        }
        return true;
    }
};