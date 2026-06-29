class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1, r=*max_element(nums.begin(),nums.end());
        while(l <= r){
            int mid = l + (r-l)/2;
            long long sum=0;
            for(auto it: nums){
                sum += ceil((double)it / (double)mid);
            }
            if(sum <= threshold){
                r=mid-1;
            }
            else l=mid+1;
        }
        return l;
    }
};