class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> in(numCourses);
        for (vector<int> vec: prerequisites) {
            in[vec[0]]++;
            adj[vec[1]].push_back(vec[0]);
        }
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!in[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            ans.push_back(cur);
            for (int num: adj[cur]) {
                in[num]--;
                if (!in[num]) {
                    q.push(num);
                }
            }
        }
        vector<int> none;
        return ans.size() == numCourses ? ans : none;
    }
};