class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int>sumLeft(n,0);
        vector<int>sumRight(n,0);

        int sumL = 0;
        for(int i=0;i<n;i++){
            sumLeft[i] = sumL;
            sumL = sumL + nums[i];
        }

        int sumR = 0;
        for(int i=n-1;i>=0;i--){
            sumRight[i] = sumR;
            sumR = sumR + nums[i];
        }

        for(int i=0;i<n;i++){
            if(sumLeft[i] == sumRight[i]){
                return i;
            }
        }
        return -1;
    }
};