class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        if(edges.size() == n-1) return 1;

        vector<bool> visited(n,false);
        vector<vector<int>> adj(n);

        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int count = 0;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count++;
                dfs(adj, visited, i);
            }
        }

        return count;
    }

    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node){
        visited[node] = true;
        for(int nei: adj[node]){
            if(!visited[nei]){
                dfs(adj, visited, nei);
            }
        }
    }
};
