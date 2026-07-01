class Solution {
public:
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};

    bool helper(vector<vector<int>> &dist, int mid){
        int n=dist.size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool> (n,false));
        q.push({0,0});
        vis[0][0] = true;

        if(dist[0][0] < mid) return false;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int x=it.first;
            int y=it.second;
            if(x==n-1 && y==n-1) return true;

            for(int i=0;i<4;i++){
                int row = dr[i] + x;
                int col = dc[i] + y;
                if(row>=0 && row<n && col>=0 && col<n && dist[row][col] >= mid && !vis[row][col]){
                    vis[row][col] = true;
                    q.push({row,col});
                }
            }
        }
        return false;
    }
    

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int> (n,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r=it.first;
            int c=it.second;

            for(int i=0;i<4;i++){
                int row = dr[i] + r;
                int col = dc[i] + c;
                if(row>=0 && row<n && col>=0 && col<n && dist[row][col] == 1e9){
                    dist[row][col] = dist[r][c] + 1;
                    q.push({row,col});
                }
            }
        }

        int l=0,h=2*n;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(helper(dist,mid)){
                l=mid+1;
            }
            else h=mid-1;
        }
        return h;
    }
};