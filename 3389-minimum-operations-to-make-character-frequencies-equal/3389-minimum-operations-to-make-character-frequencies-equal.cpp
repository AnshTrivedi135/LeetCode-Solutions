class Solution {
public:
    int makeStringGood(string s) {
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        int ans = s.size();

        int mx = *max_element(cnt.begin(), cnt.end());

        for (int target = 1; target <= mx; target++) {
            vector<int> dp(27, 0);

            for (int i = 25; i >= 0; i--) {
                int makeZero = cnt[i];
                int makeTarget = abs(cnt[i] - target);

                dp[i] = min(makeZero, makeTarget) + dp[i + 1];

                if (i + 1 < 26 && cnt[i + 1] < target) {
                    int deficit = target - cnt[i + 1];

                    int change = cnt[i] <= target
                               ? cnt[i]
                               : cnt[i] - target;

                    int cost;

                    if (deficit > change)
                        cost = change + (deficit - change);
                    else
                        cost = deficit + (change - deficit);

                    dp[i] = min(dp[i], cost + dp[i + 2]);
                }
            }

            ans = min(ans, dp[0]);
        }

        return ans;
    }
};