class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        
        if (n <= 2)
            return n;
        
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            
            map<pair<int, int>, int> mp;
            
            for (int j = i + 1; j < n; j++) {
                
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                
                // Vertical line
                if (dx == 0) {
                    dy = 1;
                    dx = 0;
                }
                
                // Horizontal line
                else if (dy == 0) {
                    dy = 0;
                    dx = 1;
                }
                
                else {
                    int g = gcd(abs(dy), abs(dx));
                    
                    dy /= g;
                    dx /= g;
                    
                    // Keep sign consistent
                    if (dx < 0) {
                        dx = -dx;
                        dy = -dy;
                    }
                }
                
                mp[{dy, dx}]++;
                
                ans = max(ans, mp[{dy, dx}] + 1);
            }
        }
        
        return ans;
    }
};