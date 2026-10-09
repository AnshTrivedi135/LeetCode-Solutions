
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> freq;
        int sum = 0;

        for (int x : nums) {
            freq[x]++;
        }

        for (int x : nums) {
            if (freq[x] == 1) {
                sum += x;
            }
        }

        return sum;
    }
};
