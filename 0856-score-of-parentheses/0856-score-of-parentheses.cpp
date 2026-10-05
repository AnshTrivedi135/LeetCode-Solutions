class Solution {
public:
    int scoreOfParentheses(string s) {
        int a=0;
        int b=1;
        for(int i=1;i<s.size();i++){
            if(s[i]=='('){
                b++;
            }else{
                b--;
             if(s[i-1]!=')'){
             a+=pow(2,b);

             }
            }
        }
        return a;
    }
};