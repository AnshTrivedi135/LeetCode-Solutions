class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, long long> mp;

        int xr = 0;
        long long ans = 0;

        mp[0] = 1;

        for (int x : nums) {
            xr ^= x;

            if (mp.count(xr))
                ans += mp[xr];

            mp[xr]++;
        }

        return ans;
    }
};