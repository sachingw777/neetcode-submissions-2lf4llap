class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;

        vector<vector<int>> adj(n);

        for(auto& e :edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n,false);

        dfs(0, adj, visited);

        for(bool v : visited){
            if(!v) return false;
        }

        return true;
    }

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        for(int nei : adj[node]){
            if(!visited[nei]){
                dfs(nei, adj, visited);
            }
        }
    }
};
