
class Solution {
public:
    long long numOfSubsequences(string s) {
        auto calc = [&](string t) {
            long long cnt = 0, a = 0;

            for (char c : s) {
                if (c == t[1]) {
                    cnt += a;
                }
                if (c == t[0]) {
                    a++;
                }
            }

            return cnt;
        };

        long long l = 0;
        long long r = count(s.begin(), s.end(), 'T');

        long long ans = 0, mx = 0;

        for (char c : s) {
            if (c == 'T') {
                r--;
            }

            if (c == 'C') {
                ans += l * r;
            }

            if (c == 'L') {
                l++;
            }

            mx = max(mx, l * r);
        }

        mx = max(mx, calc("LC"));
        mx = max(mx, calc("CT"));

        return ans + mx;
    }
};
