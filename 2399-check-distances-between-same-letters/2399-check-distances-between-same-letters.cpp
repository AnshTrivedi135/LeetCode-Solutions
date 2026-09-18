class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        
        vector<int> first(26, -1);

        for (int i = 0; i < s.size(); i++) {
            
            int c = s[i] - 'a';

            // First occurrence
            if (first[c] == -1) {
                first[c] = i;
            }
            else {
                // Second occurrence
                int gap = i - first[c] - 1;

                if (gap != distance[c])
                    return false;
            }
        }

        return true;
    }
};