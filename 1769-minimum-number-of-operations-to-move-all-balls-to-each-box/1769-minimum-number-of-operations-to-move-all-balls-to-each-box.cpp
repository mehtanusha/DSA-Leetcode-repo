class Solution {
public:
    vector<int> minOperations(string boxes) {
        //brute force
        int n = boxes.size();
        vector<int> ans(n, 0);
        
        //left to right
        int balls = 0;
        int operations = 0;
        for(int i = 0; i < n; i++) {
            ans[i] += operations;

            if(boxes[i] == '1'){
                balls++;
            }
            operations += balls;
        }

         balls = 0;
         operations = 0;
        for(int i = n-1; i>=0; i--) {
            ans[i] += operations;

            if(boxes[i] == '1'){
                balls++;
            }
            operations += balls;
        }

        return ans;
    }
};