class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        vector<vector<int>> ans, res;
        for(auto it: occupiedIntervals){
            if(ans.empty() || ans.back()[1]+1 < it[0]){
                ans.push_back(it);
            }else{
                ans.back()[1] = max(ans.back()[1], it[1]);
            }
        }
        
        for(auto &it: ans){
            int l = it[0];
            int r = it[1];
            if(r < freeStart || l > freeEnd) res.push_back({l,r});
            else {
                if(l < freeStart) res.push_back({l, freeStart - 1});
                if(r > freeEnd)  res.push_back({freeEnd + 1, r});
            }
        }
        return res;
    }
};