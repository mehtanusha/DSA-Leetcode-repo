class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int secondmaxi = INT_MIN;
        int thirdmaxi = INT_MIN;
        int smallest = INT_MAX;
        int secsmall = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > maxi){
                thirdmaxi = secondmaxi;
                secondmaxi = maxi;
                maxi = nums[i];
            }
            else if(nums[i] > secondmaxi){
                thirdmaxi = secondmaxi;
                secondmaxi = nums[i];
            }else if(nums[i] > thirdmaxi){
                thirdmaxi = nums[i];
            }
            if(nums[i] < smallest){
                secsmall = smallest;
                smallest = nums[i];
            }
            else if(nums[i] < secsmall){
                secsmall = nums[i];
            }
        }
        int case1 = maxi * secondmaxi * thirdmaxi;
        int case2 = maxi * smallest * secsmall;

        return max(case1,case2);
    }
};