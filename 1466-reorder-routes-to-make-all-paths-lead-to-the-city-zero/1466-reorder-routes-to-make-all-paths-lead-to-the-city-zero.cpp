
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : connections) {
            int u = e[0], v = e[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }

        int ans = 0;
        vector<bool> vis(n, false);

        function<void(int)> dfs = [&](int u) {
            vis[u] = true;

            for (auto [v, cost] : adj[u]) {
                if (!vis[v]) {
                    ans += cost;
                    dfs(v);
                }
            }
        };

        dfs(0);
        return ans;
    }
};
