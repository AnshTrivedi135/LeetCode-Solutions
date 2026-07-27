#include <vector>
#include <unordered_map>

class Solution {
public:
    int numberOfBoomerangs(std::vector<std::vector<int>>& points) {
        int totalBoomerangs = 0;
        int n = points.size();

        for (int i = 0; i < n; ++i) {
            std::unordered_map<int, int> distCount;

            for (int j = 0; j < n; ++j) {
                if (i == j) continue;

                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int distSq = dx * dx + dy * dy;

                distCount[distSq]++;
            }

            for (const auto& [dist, count] : distCount) {
                if (count > 1) {
                    totalBoomerangs += count * (count - 1);
                }
            }
        }

        return totalBoomerangs;
    }
};
