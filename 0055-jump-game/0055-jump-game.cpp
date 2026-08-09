class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> dp(n,false);

        dp[0]=true;
        for(int i=0;i<n;i++){
            if(dp[i] == false) continue;

            for(int j=i+1;j<=min(n-1, nums[i] + i);j++){
                dp[j] = true;
            }
        }
        return dp[n-1];
    }
};