class Solution {
public:
    unordered_set<string> ans;
    int n;

    void dfs(string &s, int i, int leftRem, int rightRem,
             int leftCnt, int rightCnt, string cur) {

        if (i == n) {
            if (leftRem == 0 && rightRem == 0) {
                ans.insert(cur);
            }
            return;
        }

        // Invalid prefix
        if (leftCnt < rightCnt)
            return;

        // Not enough characters remaining to delete
        if (n - i < leftRem + rightRem)
            return;

        // Delete current '('
        if (s[i] == '(' && leftRem > 0) {
            dfs(s, i + 1, leftRem - 1, rightRem,
                leftCnt, rightCnt, cur);
        }

        // Delete current ')'
        if (s[i] == ')' && rightRem > 0) {
            dfs(s, i + 1, leftRem, rightRem - 1,
                leftCnt, rightCnt, cur);
        }

        // Keep current character
        cur += s[i];

        if (s[i] == '(') {
            dfs(s, i + 1, leftRem, rightRem,
                leftCnt + 1, rightCnt, cur);
        }
        else if (s[i] == ')') {
            dfs(s, i + 1, leftRem, rightRem,
                leftCnt, rightCnt + 1, cur);
        }
        else {
            dfs(s, i + 1, leftRem, rightRem,
                leftCnt, rightCnt, cur);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRem = 0;
        int rightRem = 0;

        // Find minimum brackets to remove
        for (char c : s) {

            if (c == '(') {
                leftRem++;
            }
            else if (c == ')') {

                if (leftRem > 0)
                    leftRem--;
                else
                    rightRem++;
            }
        }

        n = s.size();

        dfs(s, 0, leftRem, rightRem, 0, 0, "");

        return vector<string>(ans.begin(), ans.end());
    }
};