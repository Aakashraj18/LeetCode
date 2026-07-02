class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<pair<int,int> , pair<int, int>>> q;
        vector<vector<int>> pos(m, vector<int> (n,-1));
        q.push({{0,0},{k,0}});
        pos[0][0] = k;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r=it.first.first;
            int c=it.first.second;
            int obstacles=it.second.first;
            int step=it.second.second;

            if(r==m-1 && c==n-1) return step;

            for(int i=0;i<4;i++){
                int row=dr[i]+r;
                int col=dc[i]+c;
                if(row>=0 && row<m && col>=0 && col<n && obstacles - grid[row][col] >=0 &&
                obstacles - grid[row][col] > pos[row][col]){
                    q.push({{row, col}, {obstacles - grid[row][col], step+1}});
                    pos[row][col] = obstacles - grid[row][col];
                }
            }
        }
        return -1;
    }
};