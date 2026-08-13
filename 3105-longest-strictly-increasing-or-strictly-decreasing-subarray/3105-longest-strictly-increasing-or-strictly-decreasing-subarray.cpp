class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inclength = 1;
        int declength = 1;
        int maxlength = 1;

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1] > nums[i]){
                inclength++;
                declength = 1;
            }
            else if(nums[i+1] < nums[i]){
                declength++;
                inclength = 1;
            } else{
                inclength = 1;
                declength = 1;
            }
            maxlength = max(maxlength , max(inclength,declength));
        }
        return maxlength;
    }
};