class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        if(n<=1) return 1;
        sort(arr.begin(),arr.end());
        int maxi=0;
        arr[0]=1;
        for(int i=1;i<n;i++){
            if(arr[i] > arr[i-1]){
                arr[i]=arr[i-1]+1;
            }
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }
};