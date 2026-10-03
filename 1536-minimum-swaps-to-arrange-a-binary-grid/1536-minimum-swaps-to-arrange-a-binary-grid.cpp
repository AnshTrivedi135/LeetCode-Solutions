class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n);

        for(int i = 0; i < n; i++) {
            int j = n - 1;
            while(j >= 0 && grid[i][j] == 0)
                j--;
            zeros[i] = n - 1 - j;
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            int j = i;

            while(j < n && zeros[j] < n - 1 - i)
                j++;

            if(j == n)
                return -1;

            while(j > i) {
                swap(zeros[j], zeros[j - 1]);
                j--;
                ans++;
            }
        }

        return ans;
    }
};