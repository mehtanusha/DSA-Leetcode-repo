class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int repeating = 0;
        int missing = 0;

        for(int i=0;i<n;i++){
            int idx = abs(nums[i]) - 1;
            if(nums[idx] > 0){
                nums[idx] = - nums[idx];
            }else{
                repeating = abs(nums[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                missing = i+1;
                break;
            }
        }
        return {repeating,missing};
       
    }
};