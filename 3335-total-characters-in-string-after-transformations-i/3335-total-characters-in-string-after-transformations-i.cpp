class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;

        vector<long long> cnt(26, 0);

        // Initial frequency of each character
        for (char c : s) {
            cnt[c - 'a']++;
        }

        while (t--) {
            vector<long long> next(26, 0);

            // a -> b, b -> c, ..., y -> z
            for (int i = 0; i < 25; i++) {
                next[i + 1] = cnt[i];
            }

            // z -> "ab"
            next[0] = cnt[25];
            next[1] = (next[1] + cnt[25]) % MOD;

            cnt = next;
        }

        long long ans = 0;

        for (int i = 0; i < 26; i++) {
            ans = (ans + cnt[i]) % MOD;
        }

        return ans;
    }
};