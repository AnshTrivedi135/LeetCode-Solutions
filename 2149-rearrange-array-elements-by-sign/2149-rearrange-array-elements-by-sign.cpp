class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       int n=nums.size();
       vector<int> ans(n);
       int pos=0;
       int neg=1;
       for(int m:nums){
        if(m>0){
            ans[pos]=m;
            pos+=2;
        }
        else{
            ans[neg]=m;
            neg+=2;
        }
       } 
       return ans;
    }
};