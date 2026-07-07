class Solution {
public:
    long long sumAndMultiply(int n) {
        int num=0;
        int ans=0,i=1;
        while(n!=0){
            int d=n%10;
            if(d!=0){
                num += d*i;
                i=i*10;
            }
            ans +=d;
            n/=10;
        }
        return (1LL)*num*ans;
    }
};