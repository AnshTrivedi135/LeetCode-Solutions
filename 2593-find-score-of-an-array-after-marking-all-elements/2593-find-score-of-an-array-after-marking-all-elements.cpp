
class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n, false);
        long long score = 0;

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        for (auto& p : arr) {
            int val = p.first;
            int idx = p.second;

            if (marked[idx]) {
                continue;
            }

            score += val;
            marked[idx] = true;

            if (idx > 0) {
                marked[idx - 1] = true;
            }
            if (idx < n - 1) {
                marked[idx + 1] = true;
            }
        }

        return score;
    }
};
