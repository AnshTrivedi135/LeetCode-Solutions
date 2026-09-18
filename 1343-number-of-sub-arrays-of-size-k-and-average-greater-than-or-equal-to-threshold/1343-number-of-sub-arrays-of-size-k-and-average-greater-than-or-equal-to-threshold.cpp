class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int target = k * threshold;
        int sum = 0;
        int count = 0;

        // First window
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        if (sum >= target) {
            count++;
        }

        // Slide the window
        for (int i = k; i < arr.size(); i++) {
            sum += arr[i];       // add new element
            sum -= arr[i - k];   // remove old element

            if (sum >= target) {
                count++;
            }
        }

        return count;
    }
};