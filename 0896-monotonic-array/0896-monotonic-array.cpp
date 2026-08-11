class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int dir = 0;  // 0 = not decided, 1 = increasing, -1 = decreasing

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] > nums[i - 1]) {
                if(dir == -1) return false;
                dir = 1;
            }

            else if(nums[i] < nums[i - 1]) {
                if(dir == 1) return false;
                dir = -1;
            }
        }

        return true;
    }
};