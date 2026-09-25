class Solution {
public:

    set<string> combine(set<string> a, set<string> b) {
        set<string> res;

        for (string x : a) {
            for (string y : b) {
                res.insert(x + y);
            }
        }

        return res;
    }

    set<string> unite(set<string> a, set<string> b) {
        a.insert(b.begin(), b.end());
        return a;
    }

    set<string> parse(string &s, int &i) {
        set<string> res;
        set<string> cur;

        cur.insert("");

        while (i < s.size() && s[i] != '}') {

            // Comma -> finish current part and start another
            if (s[i] == ',') {
                res = unite(res, cur);
                cur.clear();
                cur.insert("");

                i++;
            }

            // Opening brace -> recursively parse
            else if (s[i] == '{') {
                i++; // skip '{'

                set<string> inside = parse(s, i);

                // Concatenate current result with inside
                cur = combine(cur, inside);

                i++; // skip '}'
            }

            // Normal character
            else {
                string ch(1, s[i]);

                set<string> temp;
                temp.insert(ch);

                cur = combine(cur, temp);

                i++;
            }
        }

        // Add last part
        res = unite(res, cur);

        return res;
    }

public:
    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = parse(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};