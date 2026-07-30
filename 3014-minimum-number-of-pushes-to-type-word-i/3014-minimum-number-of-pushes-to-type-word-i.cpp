class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int k = 1;
        int ans = 0;

        for(int i=0;i<n/8;i++){
            ans = ans + k*8;
            k++;
        }
        ans = ans + k * (n%8);
        return ans;
    }
};