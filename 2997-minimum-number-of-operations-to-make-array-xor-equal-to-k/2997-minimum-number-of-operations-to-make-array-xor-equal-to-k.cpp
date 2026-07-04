class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        for(auto it: nums){
            ans = ans ^ it;
        }
        ans = ans ^ k;
        int cnt=0;
        while(ans != 0){
            cnt += ans & 1;
            ans = ans>>1;
        }
        return cnt;
    }
};