class Solution {
public:
    
    int findIndex(vector<vector<int>>& mat, int n, int col){
        int maxval=-1, idx=-1;
        for(int i=0;i<n;i++){
            if(mat[i][col] >= maxval){
                maxval = mat[i][col];
                idx=i;
            }
        }
        return idx;
    }


    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0, high=m-1;
        while(low <= high){
            int mid = (low + high)/2;
            int idx = findIndex(mat, n, mid);
            int left = mid-1 >= 0 ? mat[idx][mid-1] : -1;
            int right = mid+1 < m ? mat[idx][mid+1] : -1;
            if(mat[idx][mid] >= left && mat[idx][mid] >= right) return {idx, mid};
            else if(mat[idx][mid] >= left && mat[idx][mid] <= right) low=mid+1;
            else high=mid-1;
        }
        return {-1,-1};
    }
};