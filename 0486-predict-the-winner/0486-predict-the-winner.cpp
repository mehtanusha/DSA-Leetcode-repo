class Solution {
public:
    int t[23][23];

    int solve(int i, int j, vector<int>& nums) {

        if(i == j)
            return nums[i];

        if(t[i][j] != -1)
            return t[i][j];

        int takeLeft = nums[i] - solve(i + 1, j, nums);
        int takeRight = nums[j] - solve(i, j - 1, nums);

        return t[i][j] = max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));

        return solve(0, n - 1, nums) >= 0;
    }
};