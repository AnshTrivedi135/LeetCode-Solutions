class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        // Case 1: Count existing 1s
        int ones = 0;

        for (int x : nums) {
            if (x == 1)
                ones++;
        }

        // If 1 already exists
        if (ones > 0) {
            return n - ones;
        }

        // Case 2: Find shortest subarray with GCD = 1
        int minLen = INT_MAX;

        for (int i = 0; i < n; i++) {

            int g = nums[i];

            for (int j = i + 1; j < n; j++) {

                g = gcd(g, nums[j]);

                if (g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break;
                }
            }
        }

        // Impossible to create 1
        if (minLen == INT_MAX) {
            return -1;
        }

        // Create first 1 + convert remaining elements
        return (minLen - 1) + (n - 1);
    }
};