class Solution {
public:
    void helper(vector<int>&candidates, int target, int i, vector<int>&ans, int total, vector<vector<int>>&res){
        if(total == target){
            res.push_back(ans);
            return;
        }

        if(total > target || i >= candidates.size()) return;

        ans.push_back(candidates[i]);
        helper(candidates, target,i,ans,total+candidates[i],res);
        ans.pop_back();
        helper(candidates, target,i+1,ans,total,res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        helper(candidates, target, 0, ans, 0, res);
        return res;
    }
};