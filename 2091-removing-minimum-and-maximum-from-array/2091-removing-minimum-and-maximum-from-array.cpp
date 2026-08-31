class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int small=1e9, large=-1e9;
        int s=0,l=0;

        for(int i=0;i<n;i++) {
            if(large < nums[i]){
                large = nums[i];
                l=i;
            }

            if(small > nums[i]){
                small=nums[i];
                s=i;
            }
        }
        int ans = max(s,l) + 1;
        ans = min(ans, n - min(s,l));
        if(s>l) ans = min( ans, l+1 + n-s);
        else ans = min( ans, s+1+n-l);
        return ans;
    }
};