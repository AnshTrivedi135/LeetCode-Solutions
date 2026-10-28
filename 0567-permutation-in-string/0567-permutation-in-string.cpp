
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }

        vector<int> freq(26, 0);

        for (char c : s1) {
            freq[c - 'a']++;
        }

        int left = 0;
        int k = s1.size();

        for (int right = 0; right < s2.size(); right++) {
            freq[s2[right] - 'a']--;

            if (right - left + 1 > k) {
                freq[s2[left] - 'a']++;
                left++;
            }

            if (right - left + 1 == k) {
                bool match = true;

                for (int i = 0; i < 26; i++) {
                    if (freq[i] != 0) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    return true;
                }
            }
        }

        return false;
    }
};
