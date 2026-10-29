class Solution {
public:
    long long mod = 1e9 + 7;

    long long pow(long long num , long long power){
        if(power==0){
            return 1;
        }
        if(power%2 == 0){
            return pow((num*num)%mod,power/2)%mod;
        }
            return (num * pow((num*num)%mod,(power-1)/2))%mod;
    }
    int countGoodNumbers(long long n) {
        long long  even = (n+1)/2;
        long long  odd = n/2;

        return pow(5,even) * pow(4,odd)%mod;
    }
};