class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26,0);
        for(char c: s) lastIndex[c-'a']++;

        vector<bool> instack(26, false);
        string res;

        for(char ch: s){
            lastIndex[ch-'a']--;
            if(instack[ch-'a']) continue;

            while(!res.empty() && res.back() > ch && lastIndex[res.back()-'a'] > 0){
                instack[res.back()-'a'] = false;
                res.pop_back();
            }
            res.push_back(ch);
            instack[ch-'a'] = true;
        }
        return res;
    }
};