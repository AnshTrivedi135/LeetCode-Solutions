class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;
        int n = apples.size();
        int day = 0, ans = 0;
        while (day < n || !pq.empty()) {
            if (day < n && apples[day] > 0) {
                pq.push({day + days[day], apples[day]});
            }
            while (!pq.empty() &&
                   (pq.top().first <= day || pq.top().second == 0)) {
                pq.pop();
            }
            if (!pq.empty()) {
                auto cur = pq.top();
                pq.pop();
                ans++;
                cur.second--;
                if (cur.second > 0)
                    pq.push(cur);
            }
            day++;
        }
        return ans;
    }
};