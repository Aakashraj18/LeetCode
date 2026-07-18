class Solution {
public:
    long long fun(vector<int>&arr, int a, int b){
        long long ans=0,c1=0,c2=0;
        for(auto &it: arr){
            if(it < a) ans +=c1+c2;
            else if(it<=b){
                ans +=c2;
                c1++;
            }
            else c2++;
        }
        return ans;
    }
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int MOD = int(1e9 + 7);
        return fun(nums,a,b) % MOD;
    }
};