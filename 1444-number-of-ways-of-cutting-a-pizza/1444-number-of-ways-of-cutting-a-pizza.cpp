class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size();
        int n = pizza[0].size();
        int MOD = 1e9 + 7;

        vector<vector<int>> apples(m + 1, vector<int>(n + 1, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                apples[i][j] = apples[i + 1][j]
                             + apples[i][j + 1]
                             - apples[i + 1][j + 1]
                             + (pizza[i][j] == 'A');
            }
        }

        vector<vector<vector<int>>> dp(
            k + 1, vector<vector<int>>(m, vector<int>(n, 0))
        );

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[1][i][j] = (apples[i][j] > 0);
            }
        }

        for (int pieces = 2; pieces <= k; pieces++) {
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {

                    for (int r = i + 1; r < m; r++) {
                        if (apples[i][j] - apples[r][j] > 0) {
                            dp[pieces][i][j] =
                                (dp[pieces][i][j] + dp[pieces - 1][r][j]) % MOD;
                        }
                    }

                    for (int c = j + 1; c < n; c++) {
                        if (apples[i][j] - apples[i][c] > 0) {
                            dp[pieces][i][j] =
                                (dp[pieces][i][j] + dp[pieces - 1][i][c]) % MOD;
                        }
                    }
                }
            }
        }

        return dp[k][0][0];
    }
};