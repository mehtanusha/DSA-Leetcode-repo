class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int profit = 0;
        int ans = 0;
        for(int i=1;i<n;i++){
            profit = prices[i] - prices[i-1];
            if(profit > 0){
                ans += profit;
            }
        }
        return ans;
    }
};