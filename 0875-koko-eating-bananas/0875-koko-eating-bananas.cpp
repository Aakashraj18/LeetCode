class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=0;
        int l=1, r=*max_element(piles.begin(),piles.end());
        while(l <= r){
            int mid = l + (r-l)/2;
            long long count=0;
            for(auto it: piles){
                count += (double)it/ (double)mid;
                if(it%mid) count++;
            }
            if(count <= h){
                ans = mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};