class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        
        int n = vals.size();
        
        vector<vector<int>> graph(n);
        
        // Graph banana
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            graph[u].push_back(vals[v]);
            graph[v].push_back(vals[u]);
        }
        
        int ans = INT_MIN;
        
        // Har node ko center maanenge
        for (int i = 0; i < n; i++) {
            
            // Center ki value
            int sum = vals[i];
            
            // Neighbors ko sort karo
            sort(graph[i].rbegin(), graph[i].rend());
            
            // Maximum k neighbors lo
            for (int j = 0; j < min(k, (int)graph[i].size()); j++) {
                
                // Negative value lene ka koi fayda nahi
                if (graph[i][j] <= 0)
                    break;
                
                sum += graph[i][j];
            }
            
            ans = max(ans, sum);
        }
        
        return ans;
    }
};