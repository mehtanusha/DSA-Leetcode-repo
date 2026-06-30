class Solution {
public:
    int dp[10001];

    int solve(vector<int>& nums, int idx) {

        int n = nums.size();

        if(idx >= n - 1)
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int mini = INT_MAX;

        for(int jump = 1; jump <= nums[idx]; jump++) {

            int ans = solve(nums, idx + jump);

            if(ans != INT_MAX)
                mini = min(mini, 1 + ans);
        }

        return dp[idx] = mini;
    }

    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0);
    }
};