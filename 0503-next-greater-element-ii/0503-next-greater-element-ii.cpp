class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i=2*n-1;i>=0;i--){
            int x=i%n;
            while(!st.empty() && st.top() <= nums[x]){
                st.pop();
            }
            if(!st.empty() && i<n) ans[i] = st.top();
            st.push(nums[x]);
        }
        return ans;
    }
};