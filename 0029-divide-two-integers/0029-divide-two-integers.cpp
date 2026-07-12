class Solution {
public:
    int divide(int dividend, int divisor) {
        int sum = 0;
        if(dividend == divisor) return 1;
        
        bool sign = true;
        if(dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0) {
            sign = false;
        }
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans = 0;
        long long cnt;
        while(n >= d){
            cnt = 0;
            while(n >= (d << (cnt+1))){
                cnt++;
            }
            ans = ans + (1LL << cnt);
            n = n - (d *(1LL << cnt));
        }
        if(ans >= INT_MAX && sign == true){
            return INT_MAX;
        }
        if(ans > INT_MAX && sign == false){
            return INT_MIN;
        }

        return sign ? ans: (-1 * ans);
    }
};