class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]); 
        }

        vector<int> visited(numCourses, 0); 

        function<bool(int)> dfs = [&](int node) {
            if (visited[node] == 1) return false; 
            if (visited[node] == 2) return true;  

            visited[node] = 1; 
            for (int nei : graph[node]) {
                if (!dfs(nei)) return false;
            }
            visited[node] = 2; 
            return true;
        };

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) return false;
        }
        return true;
    }
};
