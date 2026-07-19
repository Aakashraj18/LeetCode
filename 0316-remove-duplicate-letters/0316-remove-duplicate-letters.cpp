class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        vector<int> lastIndex(26);
        for(int i=0;i<n;i++) lastIndex[s[i]-'a'] = i;

        vector<int> instack(26,0);
        string res;

        for(int i=0;i<n;i++){
            char ch = s[i];
            if(instack[s[i]-'a']) continue;

            while(!res.empty() && res.back() > ch && lastIndex[res.back()-'a'] > i){
                instack[res.back()-'a'] = 0;
                res.pop_back();
            }
            res.push_back(ch);
            instack[ch-'a']=1;
        }
        return res;
    }
};