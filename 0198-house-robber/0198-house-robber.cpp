class Solution {
    // int helper(vector<int> nums,int i){
    //     int n=nums.size();
    //     if(i>=n) return 0;
    //     int pick = nums[i] + helper(nums,i+2);
    //     int notpick = 0 + helper(nums,i+1);
    //     return max(pick,notpick);
    // }
    
    int helper(vector<int> nums,int i){
        int n=nums.size();
        if(i<0) return 0;
        int pick = nums[i] + helper(nums,i-2);
        int notpick = 0 + helper(nums,i-1);
        return max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1) pick += dp[i-2];
            int notpick = 0 + dp[i-1];
            dp[i] = max(pick ,notpick);
        }
        return dp[n-1];
        //return helper(nums,n-1);
    }
};