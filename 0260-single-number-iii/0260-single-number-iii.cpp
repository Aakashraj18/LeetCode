class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto it: nums) ans = ans ^ it;
        ans = (unsigned int)ans & -(unsigned int)ans;
        int b1=0, b2=0;
        for(auto it: nums){
            if( !(it & ans)) b1 = b1 ^ it;
            else b2 = b2 ^ it;
        }
        return {b1, b2};
    }
};