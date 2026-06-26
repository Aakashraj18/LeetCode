class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=0;
        int balance = n+1;
        vector<int> freq(2*n + 2);   // number of times balance i has appeared so far
        vector<int> pref(2*n + 2);   // number of previously seen balances less than or equal to i
        freq[balance] = 1, pref[balance] = 1;

        for(auto it: nums){
            if(it == target) balance++;
            else balance--;
            freq[balance]++;
            pref[balance] = pref[balance - 1] + freq[balance];
            ans += pref[balance - 1];
        }
        return ans;
    }
};