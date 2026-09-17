class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        
        vector<int> best(n, INT_MAX);
        
        int left = 0;
        int sum = 0;
        int ans = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            // Shrink window if sum becomes greater than target
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // Found a subarray with sum = target
            if (sum == target) {
                int len = right - left + 1;

                // Check if there is a previous non-overlapping subarray
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, best[left - 1] + len);
                }
            }

            // Store minimum valid length till current index
            if (right == 0) {
                if (sum == target)
                    best[right] = right - left + 1;
            } 
            else {
                best[right] = best[right - 1];

                if (sum == target) {
                    best[right] = min(best[right],
                                      right - left + 1);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};