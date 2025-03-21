class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& conn : connections) {
            adj[conn[0]].push_back({conn[1], 1});
            adj[conn[1]].push_back({conn[0], 0});
        }
        
        vector<bool> visit(n, false);
        queue<int> q;
        q.push(0);
        visit[0] = true;
        int changes = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& [neighbor, isForward] : adj[node]) {
                if (!visit[neighbor]) {
                    visit[neighbor] = true;
                    changes += isForward;
                    q.push(neighbor);
                }
            }
        }
        return changes;
    }
};