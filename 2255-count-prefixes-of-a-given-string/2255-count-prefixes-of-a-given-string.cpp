class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int a=0;
        for(string word:words){
            if(s.substr (0,word.length())==word){
                a++;
            }
        }
        
        return a;
    }
};