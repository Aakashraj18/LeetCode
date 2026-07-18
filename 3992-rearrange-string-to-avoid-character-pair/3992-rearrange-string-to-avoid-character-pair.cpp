class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string a,b,c;
        for(char ch: s){
            if(ch == y) a += ch;
            else if(ch == x) b += ch;
            else c += ch;
        }
        return a+c+b;
    }
};