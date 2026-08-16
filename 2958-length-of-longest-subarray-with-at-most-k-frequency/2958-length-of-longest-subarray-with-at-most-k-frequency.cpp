class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int res=0;
        unordered_map<int,int> mpp;
        while(j<n){
            mpp[nums[j]]++;
            while(mpp[nums[j]] > k){
                mpp[nums[i]]--;
                i++;
            }
            res = max(res,j-i+1);
            j++;
        }
        return res;
    }
};