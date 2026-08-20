class Solution {
public:
    int helper(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i == j) return dp[i][j] = nums[i];
        if(dp[i][j] != -1) return dp[i][j];

        int val = nums[i] - helper(i+1,j,nums,dp);
        int val2 = nums[j] - helper(i,j-1,nums,dp);
        return dp[i][j] = max(val, val2);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        return helper(0,n-1,nums,dp) >= 0;
    }
};