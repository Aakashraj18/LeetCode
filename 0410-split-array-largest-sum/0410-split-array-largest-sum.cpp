class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int l = *max_element(nums.begin(),nums.end());
        int r = accumulate(nums.begin(),nums.end(),0);
        int ans = r;
        while(l <= r){
            int mid = l + (r-l)/2;
            int cnt = 1, prev = nums[0];
            for(int i=1;i<n;i++){
                if(nums[i] + prev <= mid){
                    prev +=nums[i];
                }
                else{
                    prev = nums[i];
                    cnt++;
                }
            }
            if(cnt <= k){
                ans = mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};