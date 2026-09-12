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
            if(it.second.size() >= 3){

                int diff = it.second[1] - it.second[0];
                bool flag = true;
                
                for(int i=2;i<it.second.size();i++){
                    if(diff != it.second[i] - it.second[i-1]){
                        flag = false;
                        break;
                    }
                }
                if(flag) ct++;
            }
        }
        return ct;
    }
};