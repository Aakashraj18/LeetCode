class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while(!q.empty()){
            auto it=q.front();
            string s=it.first;
            int step=it.second;
            q.pop();

            if(s == endWord) return step;

            for(int i=0;i<s.size();i++){
                char c = s[i];
                for(char ch='a';ch<='z';ch++){
                    s[i] = ch;
                    if(st.find(s) != st.end()){
                        st.erase(s);
                        q.push({s, step+1});
                    }
                }
                s[i] = c;
            }
        }
        return 0;
    }
};