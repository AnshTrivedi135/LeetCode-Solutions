class Solution {
public:
    int minPenalty(int n, vector<int>& lights, vector<int>& arrivalTime) {
        
        int maxGreen = *max_element(lights.begin(), lights.end());

        int ans = 0;

        for (int t : arrivalTime) {
            int r = t % n;

            if (r >= maxGreen) {
                ans = max(ans, n - r);
            }
        }

        return ans;
    }
};