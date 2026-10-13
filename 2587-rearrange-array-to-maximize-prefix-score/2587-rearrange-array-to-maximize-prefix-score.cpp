
class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        long long sum = 0;
        int score = 0;

        for (int x : nums) {
            sum += x;

            if (sum > 0) {
                score++;
            } else {
                break;
            }
        }

        return score;
    }
};
