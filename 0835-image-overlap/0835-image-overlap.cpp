class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {
        
        int n = img1.size();

        vector<pair<int,int>> ones1;
        vector<pair<int,int>> ones2;

        // Store coordinates of 1s in img1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) {
                    ones1.push_back({i, j});
                }

                if (img2[i][j] == 1) {
                    ones2.push_back({i, j});
                }
            }
        }

        map<pair<int,int>, int> mp;

        int ans = 0;

        // Compare every 1 of img1 with every 1 of img2
        for (auto p1 : ones1) {
            for (auto p2 : ones2) {

                int dx = p2.first - p1.first;
                int dy = p2.second - p1.second;

                mp[{dx, dy}]++;

                ans = max(ans, mp[{dx, dy}]);
            }
        }

        return ans;
    }
};