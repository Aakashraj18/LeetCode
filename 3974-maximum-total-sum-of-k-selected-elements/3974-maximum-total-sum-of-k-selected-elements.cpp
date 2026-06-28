class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long sum=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=n-1;
        while(i >=0 && k>0){
            if(mul > 0) {
                sum +=(1LL)*nums[i]*mul;
                mul--;
            }
            else sum +=nums[i];
            i--;
            k--;
        }
        return sum;
    }
};