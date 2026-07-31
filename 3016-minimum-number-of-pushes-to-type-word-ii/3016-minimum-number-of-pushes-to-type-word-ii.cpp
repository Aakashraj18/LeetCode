class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        unordered_map<char, int> mpp;
        for(char c: word){
            mpp[c]++;
        }
        int ans=0;
        vector<int> freq;
        for(auto it: mpp) freq.push_back(it.second);

        sort(freq.begin(), freq.end(), greater<int>());
        for(int i=0;i<freq.size();i++){
            ans += freq[i] * (i/8 + 1);
        }
        return ans;
    }
};