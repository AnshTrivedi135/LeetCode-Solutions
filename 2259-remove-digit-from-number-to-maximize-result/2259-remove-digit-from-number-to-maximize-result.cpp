class Solution {
public:
    string removeDigit(string number, char digit) {
        for(int i=0;i<number.size();i++){
            if(number[i]==digit){
                if(i+1<number.size()&&number[i]<number[i+1]){
                    return number.substr(0,i)+number.substr(i+1);
                }
            }
        }
        int pos=number.rfind(digit);
        return number.substr(0,pos)+number.substr(pos+1);
    }
};