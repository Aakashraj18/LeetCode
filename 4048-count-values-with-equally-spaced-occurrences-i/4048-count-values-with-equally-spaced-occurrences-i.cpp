class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, vector<int>> mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }

        int ct=0;
        for(auto it: mpp){
            if(it.second.size() == 3){
                if(it.second[1] - it.second[0] == it.second[2] - it.second[1]) ct++;
            }
        }
        return ct;
    }
};