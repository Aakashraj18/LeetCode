class Solution {
public:
    #define ll long long
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        int m=queries.size();
        vector<ll> x(n+1, 0);
        vector<ll> prefix(n+1, 0);
        vector<ll> cnt(n+1, 0);
        int MOD = (int)1e9 + 7;

        vector<ll> power10(n+1,1);
        for(int i=1;i<n;i++){
            power10[i] = (power10[i-1] * 10) % MOD;
        }

        for(int i=1;i<=n;i++){
            int d = s[i-1] - '0';
            prefix[i] = prefix[i-1] + d;
            cnt[i] = cnt[i-1] + (d > 0);

            if(d > 0) x[i] = (x[i-1] * 10 + d) % MOD;

            else x[i] = x[i-1];
        }

        vector<int> ans;
        for(auto it: queries){
            int l= it[0] + 1;
            int r= it[1] + 1;
            int length = cnt[r] - cnt[l-1];

            ll num = (x[r] - (x[l - 1] * power10[length]) % MOD + MOD) % MOD;
            ll sum = prefix[r] - prefix[l - 1];
            ans.push_back((num * sum) % MOD);
        }
        return ans;
    }
};