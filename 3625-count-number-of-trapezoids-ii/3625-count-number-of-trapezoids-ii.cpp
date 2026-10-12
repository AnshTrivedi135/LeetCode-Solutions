
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();

        unordered_map<double, unordered_map<double, int>> lines;
        unordered_map<long long, unordered_map<double, int>> mids;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];

            for (int j = 0; j < i; j++) {
                int x2 = points[j][0], y2 = points[j][1];

                int dx = x2 - x1;
                int dy = y2 - y1;

                double slope, intercept;

                if (dx == 0) {
                    slope = 1e9;
                    intercept = x1;
                } else {
                    slope = (double)dy / dx;
                    intercept = (double)(1LL * y1 * dx - 1LL * x1 * dy) / dx;
                }

                lines[slope][intercept]++;

                long long mid = (x1 + x2 + 2000LL) * 4001
                              + (y1 + y2 + 2000LL);

                mids[mid][slope]++;
            }
        }

        long long ans = 0;

        for (auto& [slope, intercepts] : lines) {
            long long sum = 0;

            for (auto& [intercept, count] : intercepts) {
                ans += sum * count;
                sum += count;
            }
        }

        for (auto& [mid, slopes] : mids) {
            long long sum = 0;

            for (auto& [slope, count] : slopes) {
                ans -= sum * count;
                sum += count;
            }
        }

        return (int)ans;
    }
};
