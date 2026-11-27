
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;

        // Find the cheapest item
        for (auto &item : items) {
            minPrice = min(minPrice, item[1]);
        }

        // Count free items for each item type
        vector<int> freeCount(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    freeCount[i]++;
                }
            }
        }

        // dp[cost] = maximum items obtained by spending exactly cost
        vector<int> dp(budget + 1, -1e9);
        dp[0] = 0;

        // 0/1 Knapsack: buy the first copy of each item type
        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            int gain = 1 + freeCount[i];

            for (int cost = budget; cost >= price; cost--) {
                if (dp[cost - price] != -1e9) {
                    dp[cost] = max(dp[cost],
                                  dp[cost - price] + gain);
                }
            }
        }

        int ans = 0;

        // Spend remaining budget on the cheapest item
        for (int cost = 0; cost <= budget; cost++) {
            if (dp[cost] != -1e9) {
                int remaining = budget - cost;
                int extraItems = remaining / minPrice;

                ans = max(ans, dp[cost] + extraItems);
            }
        }

        return ans;
    }
};
