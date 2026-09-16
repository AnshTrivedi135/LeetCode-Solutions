class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        
        // Step 1: Sort
        sort(nums.begin(), nums.end());

        // Step 2: Prefix Sum
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }

        vector<int> ans;

        // Step 3: Binary Search for every query
        for (int q : queries) {
            int count = upper_bound(nums.begin(), nums.end(), q)
                        - nums.begin();

            ans.push_back(count);
        }

        return ans;
    }
};