class Solution {
public:
    bool equalFrequency(string word) {
        for(int i=0;i<word.size();i++){
            int freq[26]={};
            for(int j=0;j<word.size();j++){
                if(i!=j){
                    freq[word[j]-'a']++;
                }
            }
            int f=0;
            bool valid=true;
            for(int x:freq){
                if(x>0){
                    if(f==0)
                    f=x;
                    else if(f!=x){
                        valid =false;
                        break;
                    }
                }
            }
            if(valid)
            return true;
        }
        return false;
    }
};   