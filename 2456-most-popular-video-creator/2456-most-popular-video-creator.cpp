class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, 
                                                vector<string>& ids, 
                                                vector<int>& views) {
        
        unordered_map<string, long long> total;
        unordered_map<string, pair<int, string>> best;
        
        for (int i = 0; i < creators.size(); i++) {
            string c = creators[i];
            
            total[c] += views[i];
            
            if (!best.count(c) || 
                views[i] > best[c].first ||
                (views[i] == best[c].first && ids[i] < best[c].second)) {
                
                best[c] = {views[i], ids[i]};
            }
        }
        
        long long mx = 0;
        
        for (auto &p : total) {
            mx = max(mx, p.second);
        }
        
        vector<vector<string>> ans;
        
        for (auto &p : total) {
            if (p.second == mx) {
                ans.push_back({p.first, best[p.first].second});
            }
        }
        
        return ans;
    }
};