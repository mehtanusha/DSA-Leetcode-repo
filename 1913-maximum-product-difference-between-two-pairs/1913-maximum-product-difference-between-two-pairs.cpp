class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        long long maxi = INT_MIN;
        long long secmax = INT_MIN;
        long long mini = INT_MAX;
        long long secmini = INT_MAX;

        for(int i=0;i<nums.size();i++){
            if(nums[i] > maxi) {
                secmax = maxi;
                maxi = nums[i];
            }
            else if(nums[i] > secmax){
                secmax = nums[i];
            }
            if(nums[i] < mini){
                secmini = mini;
                mini = nums[i];
            } else if(nums[i] < secmini){
                secmini = nums[i];
            }
        }
        long long product = (maxi*secmax) - (mini*secmini);
        return product;
    }
};