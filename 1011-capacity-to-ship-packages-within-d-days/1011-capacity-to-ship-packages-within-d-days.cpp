class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int r=accumulate(weights.begin(),weights.end(),0);
        int ans=1e9;
        while(l <= r){
            int mid = l + (r-l)/2;
            int day=1, load=0;
            for(auto it: weights){
                if(load + it > mid){
                    day++;
                    load = it;
                }
                else load += it;
            }
            if(day <= days){
                ans = min(ans, mid);
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};