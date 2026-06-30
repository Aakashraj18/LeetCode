class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int l=1, r=position[n-1] - position[0];
        int ans = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            int cnt = 1, prev = position[0];
            for(int i=1;i<n;i++){
                if(position[i] - prev >= mid){
                    cnt++;
                    prev = position[i];
                }
                if(cnt == m) break;
            }
            if(cnt == m){
                ans = mid;
                l=mid+1;
            } else{
                r=mid-1;
            }
        }
        return ans;
    }
};