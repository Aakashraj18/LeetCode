class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // BETTER APPROACH
        // sort(nums.begin(), nums.end());      
        // int n=nums.size();
        // if(n>1 && nums[0] != nums[1]) return nums[0];
        // for(int i=1;i<n;i+=3){
        //     if(nums[i-1] != nums[i]) return nums[i-1];
        // }
        // return nums[n-1];


        // OPTIMAL APPROACH
        int ones=0, twos=0;
        for(auto it: nums){
            ones = (ones ^ it) & ~twos;
            twos = (twos ^ it) & ~ones;
        }
        return ones;
    }
};