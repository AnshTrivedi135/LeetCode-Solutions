#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<int> recoverArray(int n, std::vector<int>& sums) {
        std::sort(sums.begin(), sums.end());
        std::vector<int> ans;

        while (n > 0) {
            int diff = sums[1] - sums[0];
            std::unordered_map<int, int> freq;
            for (int s : sums) {
                freq[s]++;
            }

            std::vector<int> s0, s1;
            bool zeroInS0 = false;

            for (int s : sums) {
                if (freq[s] == 0) continue;
                freq[s]--;
                freq[s + diff]--;
                s0.push_back(s);
                s1.push_back(s + diff);
                if (s == 0) {
                    zeroInS0 = true;
                }
            }

            if (zeroInS0) {
                ans.push_back(diff);
                sums = std::move(s0);
            } else {
                ans.push_back(-diff);
                sums = std::move(s1);
            }

            n--;
        }

        return ans;
    }
};