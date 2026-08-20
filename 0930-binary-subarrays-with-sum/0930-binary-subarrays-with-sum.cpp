class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int i = 0;
        int sum = 0;
        int ans = 0;
        int cntzero = 0;

        for(int j = 0; j < n; j++) {
            sum += nums[j];

            while(sum > goal) {
                sum -= nums[i];
                i++;
                cntzero = 0;
            }

            while(i < j && nums[i] == 0) {
                cntzero++;
                i++;
            }

            if(sum == goal && i<= j) {
                ans += cntzero + 1;
            }
        }

        return ans;
    }
};