class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((1LL)*m*k > bloomDay.size()) return -1;
        int l=*min_element(bloomDay.begin(), bloomDay.end());
        int r=*max_element(bloomDay.begin(), bloomDay.end());
        int ans=-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            int ct=0, t=0;
            for(auto it: bloomDay){
                if(it <= mid) ct++;
                else{
                    t += ct/k;
                    ct=0;
                }
            }
            t +=ct/k;
            if(t < m) l=mid+1;
            else{
                ans = mid;
                r=mid-1;
            }
        }
        return ans;
    }
};