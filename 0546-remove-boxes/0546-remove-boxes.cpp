class Solution {
public:
    int dp[101][101][101];

    int solve(vector<int>& b, int l, int r, int k) {
        if (l > r) return 0;

        while (l < r && b[l] == b[l + 1]) {
            l++;
            k++;
        }

        if (dp[l][r][k] != -1)
            return dp[l][r][k];

        int ans = (k + 1) * (k + 1) + solve(b, l + 1, r, 0);

        for (int i = l + 1; i <= r; i++) {
            if (b[i] == b[l]) {
                ans = max(ans,
                    solve(b, l + 1, i - 1, 0) +
                    solve(b, i, r, k + 1)
                );
            }
        }

        return dp[l][r][k] = ans;
    }

    int removeBoxes(vector<int>& boxes) {
        memset(dp, -1, sizeof(dp));
        return solve(boxes, 0, boxes.size() - 1, 0);
    }
};