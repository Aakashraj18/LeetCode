class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long exp=n;
        if(exp<0) exp = -exp;
        while(exp > 0){
            if((exp & 1) != 0){
                ans = ans * x;
                exp--;
            }
            else{
                x = x*x;
                exp = exp>>1;
            }
        }
        if(n<0) return 1.0/ans;
        return ans;
    }
};