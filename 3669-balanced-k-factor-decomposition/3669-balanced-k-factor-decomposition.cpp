class Solution {
public:
    vector<int> ans;
    int best = INT_MAX;

    void dfs(int n, int k, int start, vector<int>& curr) {

        // Last factor
        if (k == 1) {
            if (n < start) return;

            int diff = n - curr[0];

            if (diff < best) {
                best = diff;
                ans = curr;
                ans.push_back(n);
            }

            return;
        }

        // Try all divisors
        for (long long d = start; d * d <= n; d++) {

            if (n % d == 0) {

                curr.push_back((int)d);

                dfs(n / d, k - 1, (int)d, curr);

                curr.pop_back();
            }
        }
    }

    vector<int> minDifference(int n, int k) {

        vector<int> curr;

        dfs(n, k, 1, curr);

        return ans;
    }
};