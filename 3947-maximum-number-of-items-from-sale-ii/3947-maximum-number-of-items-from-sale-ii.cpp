
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // 1. Find maximum factor and minimum price
        int maxFactor = 0;
        int minPrice = INT_MAX;

        for (auto& item : items) {
            maxFactor = max(maxFactor, item[0]);
            minPrice = min(minPrice, item[1]);
        }

        // 2. Count frequency of each factor
        vector<int> freq(maxFactor + 1, 0);

        for (auto& item : items) {
            freq[item[0]]++;
        }

        // 3. Count how many item types each factor can unlock
        vector<int> multiples(maxFactor + 1, 0);

        for (int f = 1; f <= maxFactor; f++) {
            for (int j = f; j <= maxFactor; j += f) {
                multiples[f] += freq[j];
            }

            // Exclude the item itself
            multiples[f]--;
        }

        // 4. Group profitable double-value purchases by price
        map<int, long long> slots;

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            int freeCount = multiples[factor];

            // A double-value item must cost <= 2 * minPrice
            if (freeCount > 0 && price <= 2LL * minPrice) {
                slots[price] += freeCount;
            }
        }

        long long answer = 0;

        // 5. Buy double-value items in increasing price order
        for (auto& [price, count] : slots) {
            long long canBuy = budget / price;
            long long take = min(count, canBuy);

            answer += take * 2;
            budget -= take * price;
        }

        // 6. Spend remaining budget on the cheapest item
        answer += budget / minPrice;

        return (int)answer;
    }
};
