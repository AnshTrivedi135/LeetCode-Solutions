
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> masks;
        
        for (string s : arr) {
            int mask = 0;
            bool valid = true;

            for (char c : s) {
                int bit = 1 << (c - 'a');

                if (mask & bit) {
                    valid = false;
                    break;
                }

                mask |= bit;
            }

            if (valid) {
                masks.push_back(mask);
            }
        }

        return solve(masks, 0, 0);
    }

    int solve(vector<int>& masks, int i, int mask) {
        if (i == masks.size()) {
            return __builtin_popcount(mask);
        }

        int skip = solve(masks, i + 1, mask);

        if ((mask & masks[i]) == 0) {
            int take = solve(masks, i + 1, mask | masks[i]);
            return max(take, skip);
        }

        return skip;
    }
};
