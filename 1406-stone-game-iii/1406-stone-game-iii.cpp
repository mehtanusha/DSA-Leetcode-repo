class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> dp(n + 3, 0);

        for(int i = n - 1; i >= 0; i--) {

            int take_one =
                stoneValue[i] - dp[i + 1];

            int take_two = INT_MIN;
            if(i + 1 < n) {
                take_two =
                    stoneValue[i] + stoneValue[i + 1]
                    - dp[i + 2];
            }

            int take_three = INT_MIN;
            if(i + 2 < n) {
                take_three =
                    stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2]
                    - dp[i + 3];
            }

            dp[i] = max({take_one, take_two, take_three});
        }

        if(dp[0] > 0) return "Alice";
        if(dp[0] < 0) return "Bob";

        return "Tie";
    }
};