class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> mp;
        long long day = 0;

        for (int task : tasks) {
            day++;

            if (mp.count(task)) {
                day = max(day, mp[task]);
            }

            mp[task] = day + space + 1;
        }

        return day;
    }
};