class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowsize = n-k;
        int total = 0;

        for(int i=0;i<n;i++){
            total += cardPoints[i];
        }
        
        if(windowsize == 0){
            return total;
        }
        int sum = 0;
        //first window ka sum 
         for(int i=0;i < windowsize;i++){
            sum = sum + cardPoints[i];
        }

        int end = windowsize;
        int start = 0;
        int mini = sum;
        while(end < n){
            sum = sum - cardPoints[start];
            sum = sum + cardPoints[end];

            mini = min(mini,sum);
            start++;
            end++;
        }
        return total - mini;
    }
};