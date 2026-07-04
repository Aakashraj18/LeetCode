class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(a || b || c){
            int x = a & 1;
            int y = b & 1;
            int z = c & 1;
            if(z==0) ans +=x+y;
            else if(x==0 && y==0) ans++;
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return ans;
    }
};