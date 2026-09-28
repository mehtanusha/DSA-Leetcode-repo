class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total_pts = accumulate(cardPoints.begin(),cardPoints.end(),0);

        int n = cardPoints.size();

        int i =0;
        int j=0;

        int m = n-k;
        int sum = 0;
        int ans = 0;

        while(j<n){
            sum += cardPoints[j];
            while(j-i+1 > m){
                sum -= cardPoints[i];
                i++;
            }
            if(j-i+1 == m){
                ans = max(ans,total_pts - sum);
            }
            j++;
        }
        return ans;
    }
};