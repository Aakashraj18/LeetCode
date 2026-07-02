class Solution {
public:
    bool search(vector<int>& arr, int target){
        int m=arr.size();
        int l=0, h=m-1;
        while(l <= h){
            int mid = (l+h)>>1;
            if(arr[mid] == target) return true;
            else if(arr[mid] < target) l=mid+1;
            else h=mid-1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(matrix[i][0] <= target && target <= matrix[i][m-1]){
                if(search(matrix[i], target)) return true;
            }
        }
        return false;
    }
};