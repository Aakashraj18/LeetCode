class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[0].size();

        vector<vector<int>> dp(n, vector<int> (n,1e9));

        for(int i=0;i<n;i++) dp[i][0] = triangle[i][0];

        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                int up = dp[i-1][j];
                int left = 1e9;
                if(j>0) left = dp[i-1][j-1];
                dp[i][j] = triangle[i][j] + min(up, left);
            }
        }
        int ans=1e9;
        for(int i=0;i<n;i++) ans = min( ans, dp[n-1][i]);

        return ans;
    }
};