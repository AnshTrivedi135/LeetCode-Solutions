class Solution {
public:
    int minOperations(string word1, string word2) {
        int n = word1.size();

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {

                int normal = calc(word1, word2, j, i - 1, false);

                int reversed = 1 + calc(word1, word2, j, i - 1, true);

                int cost = min(normal, reversed);

                dp[i] = min(dp[i], dp[j] + cost);
            }
        }

        return dp[n];
    }

private:
    int calc(string &word1, string &word2, int l, int r, bool rev) {
        int cnt[26][26] = {};
        int ans = 0;

        for (int i = l; i <= r; i++) {

            int j;

            if (rev)
                j = r - (i - l);
            else
                j = i;

            int a = word1[j] - 'a';
            int b = word2[i] - 'a';

            if (a == b)
                continue;

            if (cnt[b][a] > 0) {
                cnt[b][a]--;
            }
            else {
                cnt[a][b]++;
                ans++;
            }
        }

        return ans;
    }
};