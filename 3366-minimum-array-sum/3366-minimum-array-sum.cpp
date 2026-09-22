class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        const int INF = 1e9;

        // dp[i][j][l] = minimum sum after processing first i elements
        // using j operations of type 1 and l operations of type 2
        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(op1 + 1,
                vector<int>(op2 + 1, INF))
        );

        dp[0][0][0] = 0;

        for (int i = 1; i <= n; i++) {
            int x = nums[i - 1];

            for (int j = 0; j <= op1; j++) {
                for (int l = 0; l <= op2; l++) {

                    // 1. No operation
                    dp[i][j][l] =
                        min(dp[i][j][l],
                            dp[i - 1][j][l] + x);

                    // 2. Only Operation 1
                    if (j > 0) {
                        int val = (x + 1) / 2;

                        dp[i][j][l] =
                            min(dp[i][j][l],
                                dp[i - 1][j - 1][l] + val);
                    }

                    // 3. Only Operation 2
                    if (l > 0 && x >= k) {
                        dp[i][j][l] =
                            min(dp[i][j][l],
                                dp[i - 1][j][l - 1] + x - k);
                    }

                    // 4. Both operations
                    if (j > 0 && l > 0) {

                        // Operation 1 -> Operation 2
                        int half = (x + 1) / 2;

                        if (half >= k) {
                            dp[i][j][l] =
                                min(dp[i][j][l],
                                    dp[i - 1][j - 1][l - 1]
                                    + half - k);
                        }

                        // Operation 2 -> Operation 1
                        if (x >= k) {
                            int subtractFirst = x - k;
                            int val = (subtractFirst + 1) / 2;

                            dp[i][j][l] =
                                min(dp[i][j][l],
                                    dp[i - 1][j - 1][l - 1]
                                    + val);
                        }
                    }
                }
            }
        }

        int ans = INF;

        for (int j = 0; j <= op1; j++) {
            for (int l = 0; l <= op2; l++) {
                ans = min(ans, dp[n][j][l]);
            }
        }

        return ans;
    }
};