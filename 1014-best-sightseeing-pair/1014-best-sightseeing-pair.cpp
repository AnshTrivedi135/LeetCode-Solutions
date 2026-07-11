class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int best = values[0];
        int ans = INT_MIN;
        for( int i=1;i<values.size();i++){
            ans =max(ans,best+values[i]-i);
            best =max(best,values[i]+i);

        }
        return ans ;
    }
};