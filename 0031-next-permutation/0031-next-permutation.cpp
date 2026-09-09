class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();

        int idx=-1;

        // find idx whose elememt is smaller than previous just from last
        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }

        if(idx == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // replace element of idx with just bigger element from right side
        for(int i=n-1;i>idx;i--){
            if(nums[i] > nums[idx]){
                swap(nums[i], nums[idx]);
                break;
            }
        }
        
        //for(auto it: nums) cout<<it<<" ";

        // after replace in 2nd step sort element after that
        sort(nums.begin()+idx+1, nums.end());
        return;
    }
};