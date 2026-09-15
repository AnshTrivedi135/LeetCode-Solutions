class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // pal[i][j] = true if s[i...j] is palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Every single character is palindrome
        for (int i = 0; i < n; i++) {
            pal[i][i] = true;
        }

        // Check substrings of length >= 2
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {

                int j = i + len - 1;

                if (s[i] == s[j]) {
                    if (len == 2)
                        pal[i][j] = true;
                    else
                        pal[i][j] = pal[i + 1][j - 1];
                }
            }
        }

        // dp[i] = max palindromes from index i
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            // Don't take current character
            dp[i] = dp[i + 1];

            // Try every palindrome starting at i
            for (int j = i + k - 1; j < n; j++) {

                if (pal[i][j]) {
                    dp[i] = max(dp[i], 1 + dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};