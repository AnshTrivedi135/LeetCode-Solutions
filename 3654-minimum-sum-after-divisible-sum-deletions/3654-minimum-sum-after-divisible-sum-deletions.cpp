class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {

        // Required variable
        auto quorlathin = make_pair(nums, k);

        const long long INF = 1e18;

        // dp[r] = minimum remaining sum of a prefix
        // whose sum % k = r
        vector<long long> dp(k, INF);

        dp[0] = 0;

        long long sum = 0;

        for (int x : nums) {

            sum += x;

            int rem = sum % k;

            // Option 1: keep x
            long long keep = sum;

            // Option 2: delete a subarray
            // having sum divisible by k
            long long best = dp[rem];

            sum = min(keep, best);

            dp[rem] = sum;
        }

        return sum;
    }
};