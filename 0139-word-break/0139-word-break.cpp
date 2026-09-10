class Solution {
public:
    bool helper(int i, string &s, set<string> st){
        if(i == s.size()) return true;

        string temp;
        for(int j=i;j<s.size();j++){
            temp += s[j];
            if(st.find(temp) != st.end()){
                if(helper(j+1, s, st)) return true;
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(string x: wordDict){
            st.insert(x);
        }
        //return helper(0, s, st);

        vector<int> dp(s.size()+1,0);
        int n=s.size();
        dp[n] = 1;
        for(int i=n-1;i>=0;i--){
            string temp;
            for(int j=i;j<n;j++){
                temp += s[j];

                if(st.find(temp) != st.end() && dp[j+1]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};