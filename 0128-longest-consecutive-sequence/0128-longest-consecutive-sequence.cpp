class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        int a=0;
        for(int num:s){
            if(s.find(num-1)==s.end()){
                int b=num;
                int c=1;
                while(s.find(b+1)!=s.end()){
                    b++;
                    c++;
                }
                a=max(a,c);
            }
        }
        return a;
    }
};