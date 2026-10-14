
class Solution {
public:
    int rootCount(vector<vector<int>>& edges,
                  vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n);
        unordered_set<long long> st;

        auto key = [n](int u, int v) -> long long {
            return 1LL * u * n + v;
        };

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (auto& g : guesses) {
            st.insert(key(g[0], g[1]));
        }

        int cnt = 0, ans = 0;

        function<void(int, int)> dfs1 =
            [&](int u, int parent) {
                for (int v : adj[u]) {
                    if (v == parent) continue;

                    if (st.count(key(u, v)))
                        cnt++;

                    dfs1(v, u);
                }
            };

        function<void(int, int)> dfs2 =
            [&](int u, int parent) {
                if (cnt >= k)
                    ans++;

                for (int v : adj[u]) {
                    if (v == parent) continue;

                    int oldCnt = cnt;

                    if (st.count(key(u, v)))
                        cnt--;

                    if (st.count(key(v, u)))
                        cnt++;

                    dfs2(v, u);
                    cnt = oldCnt;
                }
            };

        dfs1(0, -1);
        dfs2(0, -1);

        return ans;
    }
};
