class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        
        sort(tasks.begin(), tasks.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] < b[1];
             });

        vector<int> used(2001, 0);
        int ans = 0;

        for (auto &task : tasks) {
            int start = task[0];
            int end = task[1];
            int duration = task[2];

            int already = 0;

            // Kitna time already use ho chuka hai
            for (int t = start; t <= end; t++) {
                already += used[t];
            }

            int need = duration - already;

            // Agar aur time chahiye
            // to end se peeche ki taraf time select karo
            for (int t = end; t >= start && need > 0; t--) {
                if (used[t] == 0) {
                    used[t] = 1;
                    ans++;
                    need--;
                }
            }
        }

        return ans;
    }
};