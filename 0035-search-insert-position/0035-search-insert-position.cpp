class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    int n= nums.size();
    int lo=0,hi=n-1,mid;
	int ans=n;
	while(hi >= lo){
		mid = (lo + hi)/2;
		if(nums[mid] >= target){
			ans = mid;
			hi = mid -1;
		}
		else lo = mid +1;
	}
	return ans;
    }
};