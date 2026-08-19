class Solution {
public:
    int helper(vector<int>& arr, int k){
        int n=arr.size();
        int l=0, r=n-1;
        int ans=-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(arr[mid] <= k){
                ans = mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }


    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        int m=worker.size();

        vector<pair<int, int>> v;
        for(int i=0;i<n;i++){
            v.push_back({difficulty[i], profit[i]});
        }
        sort(v.begin(), v.end());
        sort(difficulty.begin(),difficulty.end());
        for(int i=1;i<v.size();i++){
            v[i].second = max(v[i].second, v[i-1].second);
        }

        int ans=0;
        for(int i=0;i<m;i++){
            int ele = helper(difficulty, worker[i]);
            if(ele == -1) continue;
            ans += v[ele].second;
        }
        return ans;
    }
};