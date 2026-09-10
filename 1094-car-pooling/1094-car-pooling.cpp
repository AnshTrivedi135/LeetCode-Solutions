class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001,0);
        for(auto &trip :trips){
            int passengers=trip[0];
            int from =trip[1];
            int to=trip[2];
            diff[from]+=passengers;
            diff[to]-=passengers;
        }
        int currentPassengers=0;
        for(int i=0;i<=1000;i++){
            currentPassengers +=diff[i];
            if(currentPassengers >capacity){
                return false;
            }
        }
        return true;
    }
};