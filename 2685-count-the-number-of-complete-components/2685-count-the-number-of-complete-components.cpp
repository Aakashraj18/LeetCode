class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> vis(n, false);
        int ans = 0;

        for(int i=0;i<n;i++) {
            if(vis[i]) continue;
            queue<int> q;
            q.push(i);
            vis[i] = true;

            int nodes = 0;
            int edgeCount = 0; 

            while(!q.empty()){
                int u = q.front();
                q.pop();
                nodes++;
                edgeCount += adj[u].size();

                for(auto v : adj[u]){
                    if(!vis[v]){
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
            edgeCount /= 2;
            if(edgeCount == nodes * (nodes - 1) / 2)
                ans++;
        }
        return ans;
    }
};