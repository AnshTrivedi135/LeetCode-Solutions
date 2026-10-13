
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefix(n);
        vector<bool> inc(n, true), dec(n, true);

        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
            inc[i] = inc[i - 1] && (nums[i] > nums[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            dec[i] = dec[i + 1] && (nums[i] > nums[i + 1]);
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < n - 1; i++) {
            if (inc[i] && dec[i + 1]) {
                long long left = prefix[i];
                long long right = prefix[n - 1] - prefix[i];

                ans = min(ans, llabs(left - right));
            }
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};
