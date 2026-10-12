
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<int> cnt(31, 0);

        // Step 1: Count set bits at every position
        for (int num : nums) {
            for (int i = 0; i < 31; i++) {
                if ((num >> i) & 1) {
                    cnt[i]++;
                }
            }
        }

        long long ans = 0;

        // Step 2: Construct k maximum numbers
        for (int j = 0; j < k; j++) {
            long long x = 0;

            for (int i = 0; i < 31; i++) {
                if (cnt[i] > 0) {
                    x |= (1LL << i);
                    cnt[i]--;
                }
            }

            // Step 3: Add square modulo MOD
            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};
