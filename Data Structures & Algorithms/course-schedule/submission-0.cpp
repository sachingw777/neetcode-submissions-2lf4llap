class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]); // edge b -> a
        }

        vector<int> visited(numCourses, 0); 
        // 0 = unvisited, 1 = visiting, 2 = visited

        function<bool(int)> dfs = [&](int node) {
            if (visited[node] == 1) return false; // cycle
            if (visited[node] == 2) return true;  // already processed

            visited[node] = 1; // mark as visiting
            for (int nei : graph[node]) {
                if (!dfs(nei)) return false;
            }
            visited[node] = 2; // mark as visited
            return true;
        };

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) return false;
        }
        return true;
    }
};
