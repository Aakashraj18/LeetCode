class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int total = 0;
        while(l<r){
            if(height[l] <= height[r]){
                total = max(total, height[l] * (r-l));
                l++;
            }
            else{
                total = max(total , height[r] * (r-l));
                r--;
            }
        }
        return total;
    }
};