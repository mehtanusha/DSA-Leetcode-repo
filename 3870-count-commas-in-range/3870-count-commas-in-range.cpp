class Solution {
public:
    int countCommas(int n) {
        int cnt = 0;
        while( n>999 && n<=100000){
            cnt++;
            n--;
        }
        return cnt;
    }
};