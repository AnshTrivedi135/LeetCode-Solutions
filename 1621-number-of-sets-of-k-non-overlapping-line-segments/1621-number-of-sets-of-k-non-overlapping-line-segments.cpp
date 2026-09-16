class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1e9 + 7;

        // dp[i] = C(current, i)
        vector<long long> dp(2 * k + 1, 0);
        dp[0] = 1;

        int N = n + k - 1;
        int R = 2 * k;

        for (int i = 1; i <= R; i++) {
            dp[i] = 0;
        }

        // Calculate C(N, R) using Pascal's identity
        vector<vector<long long>> C(N + 1,
                                    vector<long long>(R + 1, 0));

        for (int i = 0; i <= N; i++) {
            C[i][0] = 1;

            for (int j = 1; j <= min(i, R); j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        return C[N][R];
    }
};