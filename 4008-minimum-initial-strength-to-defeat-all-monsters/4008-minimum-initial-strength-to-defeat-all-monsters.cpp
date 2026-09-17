class Solution {
public:
    long long minInitialStrength(vector<int>& monsters,
                                 vector<vector<int>>& boosts) {

        int n = monsters.size();

        // Difference array
        vector<long long> diff(n + 1, 0);

        // Apply all range boosts
        for (auto &b : boosts) {
            int l = b[0];
            int r = b[1];
            int val = b[2];

            diff[l] += val;
            diff[r + 1] -= val;
        }

        long long bonus = 0;
        long long spent = 0;
        long long answer = 0;

        for (int i = 0; i < n; i++) {

            // Total boost available for monster i
            bonus += diff[i];

            // If boost alone is not enough,
            // initial strength must cover the remaining amount
            if (bonus < monsters[i]) {
                answer = max(
                    answer,
                    spent + monsters[i] - bonus
                );
            }

            // Defeat this monster
            spent += monsters[i];
        }

        return answer;
    }
};