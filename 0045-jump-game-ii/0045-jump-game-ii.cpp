class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);

        dp[0]=0;
        for(int i=0;i<n;i++){
            if(dp[i]==-1) continue;

            for(int j=i+1;j<=min(n-1, nums[i]+i);j++){
                if(dp[j] == -1) dp[j] = dp[i]+1;
                else dp[j] = min(dp[j], dp[i]+1);
            }
        }
        return dp[n-1];
    }
};