
class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();

        vector<int> px(n + 1, 0), py(n + 1, 0);

        for (int i = 0; i < n; i++) {
            px[i + 1] = px[i];
            py[i + 1] = py[i];

            if (s[i] == 'U') py[i + 1]++;
            else if (s[i] == 'D') py[i + 1]--;
            else if (s[i] == 'L') px[i + 1]--;
            else if (s[i] == 'R') px[i + 1]++;
        }

        unordered_set<long long> points;

        int totalX = px[n];
        int totalY = py[n];

        for (int i = 0; i <= n - k; i++) {
            int removedX = px[i + k] - px[i];
            int removedY = py[i + k] - py[i];

            int finalX = totalX - removedX;
            int finalY = totalY - removedY;

            long long key = 1LL * finalX * 200001 + finalY;
            points.insert(key);
        }

        return points.size();
    }
};
