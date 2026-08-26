class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        int ans = 0;

        for (int x : answers) {
            if (mp[x] == 0) {
                ans += x + 1;
                mp[x] = x + 1;
            }
            mp[x]--;
        }

        return ans;
    }
};