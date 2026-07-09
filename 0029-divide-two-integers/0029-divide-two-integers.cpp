class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        bool flag = true;
        flag = ((dividend < 0) == (divisor < 0));
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);
        unsigned int q=0;
        while(n>=d){
            int cnt=0;
            while(n > (d<<(cnt+1))){
                cnt++;
            }
            q+= 1<<cnt;
            n-=(d<<cnt);
        }
        if(q == (1<<31) && flag){
            return INT_MAX;
        }
        return flag ? q : -q;
    }
};