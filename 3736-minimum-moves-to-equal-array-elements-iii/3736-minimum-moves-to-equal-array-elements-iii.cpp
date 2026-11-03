class Solution {
public:
    int minMoves(vector<int>& nums) {
      int n=nums.size();
      int max=*max_element(nums.begin(),nums.end());
      int ans=0;
      for(int num:nums){
        ans+=max-num;
        
      }
      return ans;
    }
};




