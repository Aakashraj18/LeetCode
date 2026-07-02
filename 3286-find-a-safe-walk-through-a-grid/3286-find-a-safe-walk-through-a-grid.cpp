class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<pair<int,int> , int>> q;
        vector<vector<int>> dist(m, vector<int> (n,0));
        q.push({{0,0}, health - grid[0][0]});
        dist[0][0] = health - grid[0][0];

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first.first;
            int c = it.first.second;
            int dis = it.second;

            for(int i=0;i<4;i++){
                int row = dr[i] + r;
                int col = dc[i] + c;
                if(row>=0 && row<m && col>=0 && col<n &&
                dis - grid[row][col] >= 1 && dist[row][col] < dis - grid[row][col]){
                    q.push({{row, col}, dis - grid[row][col]});
                    dist[row][col] = dis - grid[row][col];
                }
            }
        }
        return dist[m-1][n-1] >= 1;
    }
};