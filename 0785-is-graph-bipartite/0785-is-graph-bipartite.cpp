#include <vector>
#include <queue>

class Solution {
public:
    bool isBipartite(std::vector<std::vector<int>>& graph) {
        int n = graph.size();
        std::vector<int> color(n, 0);

        for (int i = 0; i < n; ++i) {
            if (color[i] != 0) continue;

            std::queue<int> q;
            q.push(i);
            color[i] = 1;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {
                    if (color[v] == 0) {
                        color[v] = -color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};