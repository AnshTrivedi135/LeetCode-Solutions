class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int maxright=0;
        unordered_set<char> st;
      for(int right=0;right<s.size();right++){
           while(st.count(s[right])){
            st.erase(s[left]);
            left++;
           }
           st.insert(s[right]);
           maxright=max(maxright,right-left+1);
      }
      return maxright;
    }
};