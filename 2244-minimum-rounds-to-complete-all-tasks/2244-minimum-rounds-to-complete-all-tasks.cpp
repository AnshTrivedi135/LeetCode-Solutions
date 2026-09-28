class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>freq;
        for(int task:tasks){
            freq[task]++;
        }
        int a=0;
        for(auto it :freq){
            int c=it.second;
            if(c==1)
            return -1;
            a+=(c+2)/3;

            
        }
        return a;
    }
};