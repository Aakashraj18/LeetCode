class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        int t=m*n;
        k=k%t;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int oldIdx = i*n+j;
                int newIdx = (oldIdx + k)%t;

                int row = newIdx / n;
                int col = newIdx % n;
                ans[row][col] = grid[i][j];
            }
        }
        return ans;
    }
};