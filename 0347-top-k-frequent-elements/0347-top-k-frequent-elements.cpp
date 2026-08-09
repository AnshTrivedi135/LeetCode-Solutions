class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto &p : freq) {
            bucket[p.second].push_back(p.first);
        }

        vector<int> result;

        for (int i = nums.size(); i >= 1 && result.size() < k; i--) {
            for (int num : bucket[i]) {
                result.push_back(num);

                if (result.size() == k) {
                    break;
                }
            }
        }

        return result;
    }
};