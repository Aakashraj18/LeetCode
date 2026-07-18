class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long ans = n/2;
        long long res = 1LL * s + ans * m - max(0LL,ans - 1);
        return res;
    }
};