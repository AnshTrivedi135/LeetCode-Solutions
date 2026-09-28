class Solution {
public:
    int maxDepth(string s) {
       int d=0;
       int c=0;
       for(char ch:s){
        if(ch=='('){
            d++;
            c=max(c,d);
        }
        else if(ch==')'){
            d--;
        }
       }
       return c; 
    }
};