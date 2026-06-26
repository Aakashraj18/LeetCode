class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){
            int l=i+1, h=n-1;
            while(l<h){
                if(nums[i] + nums[l] + nums[h] < 0) l++;
                else if(nums[i] + nums[l] + nums[h] >0) h--;
                else {
                    st.insert({nums[i],nums[l],nums[h]});
                    h--;
                    l++;
                }
            }
        }
        for(auto x: st){
            ans.push_back(x);
        }
        return ans;
    }
};