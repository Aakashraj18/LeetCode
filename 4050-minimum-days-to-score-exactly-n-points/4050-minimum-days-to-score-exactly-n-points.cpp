class Solution {
public:
    int minDays(int n) {
        vector<int> dp(n+1,1e9);
        vector<int> v;

        for(int i=1;(i*(i+1)/2)<=n;i++){
            v.push_back(i * (i+1)/2);
        }

        dp[0]=-1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<v.size();j++){
                if(v[j] > i) break;
                else if(dp[i-v[j]]+j+2 >= dp[i]) continue;
                else{
                    dp[i] = dp[i-v[j]]+j+2;
                }
            }
        }
        return dp[n];
    }
};