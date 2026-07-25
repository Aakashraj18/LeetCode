class Solution {
    int helper(vector<int> nums, int i,int n){
        if(i>=n) return 0;
        int pick = nums[i] + helper(nums, i+2,n);
        int notpick = 0 + helper(nums, i+1,n);
        return max(pick,notpick);
    }

    int fun(vector<int> & nums){
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1) pick += dp[i-2];
            int notpick = 0 + dp[i-1];
            dp[i] = max(pick, notpick);
        }
        return dp[n-1];
    }

public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n == 1) return nums[0];
        //return max(helper(nums,0,nums.size()-1), helper(nums,1,nums.size()));
        vector<int> v, v2;
        for(int i=0;i<n;i++){
            if(i != n-1) v.push_back(nums[i]);
            if(i != 0) v2.push_back(nums[i]);
        }
        return max(fun(v) , fun(v2));
    }
};