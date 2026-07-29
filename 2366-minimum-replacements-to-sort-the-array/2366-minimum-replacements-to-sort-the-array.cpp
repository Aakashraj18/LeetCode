class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        int l=nums[n-1];

        long long ans=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i] > l){
                int p = (nums[i] + l -1)/l;
                ans += p-1;
                l = nums[i]/p;
            }
            else l = nums[i];
        }
        return ans;
    }
};