class Solution {
public:
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) {
            this->n = n;
            bit.resize(n + 1, 0);
        }

        void add(int idx, int val) {
            for (; idx <= n; idx += idx & -idx)
                bit[idx] += val;
        }

        int query(int idx) {
            int sum = 0;

            for (; idx > 0; idx -= idx & -idx)
                sum += bit[idx];

            return sum;
        }
    };

    int countRatioSubarrays(vector<int>& nums, int a, int b) {

        int n = nums.size();

        // Required variable
        auto norvelith = nums;

        vector<long long> pref(n + 1, 0);

        // even -> +b
        // odd  -> -a
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0)
                pref[i + 1] = pref[i] + b;
            else
                pref[i + 1] = pref[i] - a;
        }

        // Coordinate compression
        vector<long long> vals = pref;

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        Fenwick fw(vals.size());

        long long ans = 0;

        for (int i = 0; i <= n; i++) {

            int idx = lower_bound(
                vals.begin(),
                vals.end(),
                pref[i]
            ) - vals.begin() + 1;

            // Count previous prefix values >= current prefix
            ans += i - fw.query(idx - 1);

            fw.add(idx, 1);
        }

        return (int)ans;
    }
};