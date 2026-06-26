class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1,mid;
        int ans=-1;
        while(i<=j){
            mid= (i+j)/2;
            if(nums[mid] > target) j=mid -1;
            else if(nums[mid]== target){
                ans = mid;
                j= mid -1;
            }
            else i=mid +1;
        }
        return ans;
    }
};