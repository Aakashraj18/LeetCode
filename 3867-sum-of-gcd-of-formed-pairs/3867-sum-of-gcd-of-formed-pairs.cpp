class Solution {
public:
    int gcd(int a,int b) {
        if(b > a) return gcd(b, a);
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long> res(n);
        res[0] = nums[0];
        int maxi=nums[0];
        for(int i=1;i<n;i++){
            maxi = max(maxi, nums[i]);
            res[i] = gcd(nums[i], maxi);
        }
        sort(res.begin(),res.end());
        int i=0, j=n-1;
        long long sum=0;
        while(i<j){
            sum += gcd(res[i], res[j]);
            i++;
            j--;
        }
        return sum;
    }
};