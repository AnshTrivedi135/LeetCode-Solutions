class Solution {
public:

    struct Node {
        long long score;
        vector<int> indices;

        Node() {
            score = 0;
        }

        Node(long long s, vector<int> v) {
            score = s;
            indices = v;
        }
    };

    vector<vector<Node>> memo;
    vector<vector<int>> a;
    int n;

    Node solve(int i, int k) {

        // No intervals left or quota finished
        if (i == n || k == 0) {
            return Node();
        }

        // Already calculated
        if (memo[i][k].score != -1) {
            return memo[i][k];
        }

        // Option 1: Skip current interval
        Node skip = solve(i + 1, k);

        int r = a[i][1];
        int weight = a[i][2];
        int originalIndex = a[i][3];

        // Find first interval with start > r
        int lo = i + 1;
        int hi = n;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (a[mid][0] > r)
                hi = mid;
            else
                lo = mid + 1;
        }

        int next = lo;

        // Option 2: Pick current interval
        Node nextState = solve(next, k - 1);

        vector<int> picked;
        picked.push_back(originalIndex);

        for (int x : nextState.indices) {
            picked.push_back(x);
        }

        sort(picked.begin(), picked.end());

        Node take(
            weight + nextState.score,
            picked
        );

        // Choose better score
        if (take.score > skip.score) {
            return memo[i][k] = take;
        }

        if (take.score < skip.score) {
            return memo[i][k] = skip;
        }

        // Equal score -> lexicographically smaller
        if (take.indices < skip.indices) {
            return memo[i][k] = take;
        }

        return memo[i][k] = skip;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        // Required copy of input
        vector<vector<int>> vorellixan = intervals;

        a.clear();

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by starting point
        sort(a.begin(), a.end());

        memo.assign(n, vector<Node>(5));

        // score = -1 means not calculated
        for (int i = 0; i < n; i++) {
            for (int k = 0; k <= 4; k++) {
                memo[i][k].score = -1;
            }
        }

        return solve(0, 4).indices;
    }
};