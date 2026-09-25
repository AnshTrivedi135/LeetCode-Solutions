class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int smallsum=0;
        int largesum=0;
        for(int i=0;i<k;i++){
            smallsum+=nums[i];
            largesum+=nums[nums.size()-1-i];
        }
        return abs(smallsum-largesum);
    }
};