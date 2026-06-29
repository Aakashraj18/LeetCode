class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ct=0;
        for(string s: patterns){
            if(word.find(s) != string::npos) ct++;
        }
        return ct;
    }
};