class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int>freq(26,0),need(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        for(char c:target){
            need[c-'a']++;
        }
        int ans=INT_MAX;
        for(int i=0;i<26;i++){
            if(need[i]>0){
                ans=min(ans,freq[i]/need[i]);
            }
        }
        return ans;
    }
};




