class DisjointSet {
public:
    vector<int> rank, size, parent;
    DisjointSet(int n){
        rank.resize(n+1,1);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }

    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void UnionBySize(int u, int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};


class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(), edgeList.end(), [](auto &a, auto &b){
            return a[2] < b[2];
        });

        vector<vector<int>> q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i][2], queries[i][0], queries[i][1], i});
        } 
        sort(q.begin(),q.end());

        DisjointSet ds(n);
        int idx=0;
        vector<bool> ans(queries.size());

        for(auto it: q){
            int limit=it[0];
            int u=it[1];
            int v=it[2];
            int i=it[3];

            while(idx < edgeList.size() && edgeList[idx][2] < limit){
                ds.UnionBySize(edgeList[idx][0], edgeList[idx][1]);
                idx++;
            }
            ans[i] = (ds.findParent(u) == ds.findParent(v));
        }
        return ans;
    }
};