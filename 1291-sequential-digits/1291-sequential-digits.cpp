class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string s="123456789";
        string l=to_string(low);
        string h=to_string(high);
        for(int i=l.size();i<=h.size();i++){
            for(int j=0;j<=9-i;j++){
                string n=s.substr(j,i);
                int number=stoi(n);
                if(number >= low && number <= high) ans.push_back(number);
            }
        }
        return ans;
    }
};