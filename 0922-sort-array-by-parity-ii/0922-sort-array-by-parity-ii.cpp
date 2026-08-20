class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
       int i = 0;
       int j =1;
       int n = nums.size();
       while(i<n && j<n){
        if(i %2 == 0 && nums[i]%2 == 0){
            i = i+2;
        }
        if(j %2 != 0 && nums[j]%2 != 0){
            j = j+2;
        }
        else{
            swap(nums[i],nums[j]);
        }
       }
       return nums;
    }
};