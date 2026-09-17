class Solution {
public:
    int ans = 0;

    void solve(string &s, int index, unordered_set<string> &st) {
        // All characters are used
        if (index == s.size()) {
            ans = max(ans, (int)st.size());
            return;
        }

        // Try every possible substring
        for (int i = index; i < s.size(); i++) {

            string sub = s.substr(index, i - index + 1);

            // If substring is not already used
            if (st.find(sub) == st.end()) {

                st.insert(sub);

                // Recursively solve remaining string
                solve(s, i + 1, st);

                // Backtrack
                st.erase(sub);
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> st;

        solve(s, 0, st);

        return ans;
    }
};