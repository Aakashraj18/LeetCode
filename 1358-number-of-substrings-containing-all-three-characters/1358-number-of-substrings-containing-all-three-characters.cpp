class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> v(3,-1);
        int maxlen=0;
        for(int i=0;i<s.size();i++){
            v[s[i] - 'a'] = i;
            if(v[0] != -1 && v[1] != -1 && v[2] != -1){
                maxlen += 1 + min({v[0],v[1],v[2]});
            }
        }
        return maxlen;
    }
};