class Solution {
public:

    long long mod = 1e9 + 7;

    long long power(long long num,long long n){
        if(n == 0){
            return 1;
        }
        if(n % 2 == 0){
            return power((num*num)%mod,n/2) % mod;
        }
        else{
            return (num *power(num,n-1))% mod; 
        }
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;

        return (power(5,even) * power(4,odd)) % mod;
    }
};