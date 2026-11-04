class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string,int> freq;
        int n=s.size();
        int ans=0;
        for(int i=0;i+minSize <=n;i++){
            string sub=s.substr(i,minSize);
            unordered_set<char>st(sub.begin(),sub.end());
            if(st.size()<=maxLetters){
                freq[sub]++;
                ans=max(ans,freq[sub]);

            }
        }
        return ans;
    }
};


