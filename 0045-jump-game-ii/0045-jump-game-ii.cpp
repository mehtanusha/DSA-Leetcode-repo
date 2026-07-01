class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        int currentend = 0;
        int i = 0;
        int jumps = 0;

        while(i<n-1){
            farthest = max(farthest,i+nums[i]);
            if(i == currentend){
                jumps++;
                currentend = farthest;
            }
            i++;
        }
        return jumps;
    }
};