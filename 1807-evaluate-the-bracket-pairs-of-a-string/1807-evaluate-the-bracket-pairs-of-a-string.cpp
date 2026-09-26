class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        // Store key -> value
        for (auto &x : knowledge) {
            mp[x[0]] = x[1];
        }

        string ans;
        int i = 0;

        while (i < s.size()) {

            if (s[i] == '(') {
                // Find closing bracket
                int j = i + 1;

                while (s[j] != ')') {
                    j++;
                }

                // Extract key
                string key = s.substr(i + 1, j - i - 1);

                // Replace with value or '?'
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                } else {
                    ans += "?";
                }

                // Move after ')'
                i = j + 1;
            }
            else {
                ans += s[i];
                i++;
            }
        }

        return ans;
    }
};