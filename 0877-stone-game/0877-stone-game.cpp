class Solution {
public:
    bool helper(int i, int j, vector<int>& piles, vector<vector<int>>& dp){
        if(i>=piles.size() || j<0) return false;
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = max(piles[i] - helper(i+1,j, piles, dp), piles[j] - helper(i, j-1,piles,dp));
    }

    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n, vector<int> (n, 1e9));
        return helper(0, n-1,piles, dp);
    }
};