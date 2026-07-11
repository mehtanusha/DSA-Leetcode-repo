class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        int nums = start ^ goal;
        while(nums != 0){
            nums = nums & (nums - 1);
            cnt++;
        }
        return cnt;
    }
};